#import <EXGL-CPP/UEXGL.h>

// Obj-C wrapper around C `ABI24_0_0EXGLObject` (identified by `ABI24_0_0EXGLObjectId`) lifetimes that
// dispatches to child classes (such as `ABI24_0_0EXGLGPUImageObject`) for the actual media
// source
//
// Could output to any OpenGL object: a texture, a shader, a program, ...
// Could be backed by any media source: camera stream, ... (more coming soon)
//
// `config` format:
//
// {
//   exglCtxId: gl.__exglCtxId, // <-- to identify the `gl` context
//   texture: {
//     camera: {
//       position: 'front' | 'back',
//     },
//   }
// }

@interface ABI24_0_0EXGLObject : NSObject

@property (nonatomic, assign) UEXGLContextId exglCtxId;
@property (nonatomic, assign) UEXGLObjectId exglObjId;

// Create an `ABI24_0_0EXGLObject` of the correct type given `config`, returns `nil` if
// bad `config`
+ (instancetype)createWithConfig:(NSDictionary *)config;

// For internal use by children -- use `[ABI24_0_0EXGLObject createWithConfig:...]` above to
// create the `ABI24_0_0EXGLObject` of the right type
- (instancetype)initWithConfig:(NSDictionary *)config;

@end
