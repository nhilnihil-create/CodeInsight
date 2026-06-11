#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    int maxZ=0,minZ=0,maxW=0,minW=0;
    for(int i=0;i<N;++i){
        int x,y;
        cin>>x;
        cin>>y;
        int z=x+y;
        int w=x-y;
        if(i==0){
            maxZ=minZ=z;
            maxW=minW=w;
        }else{
            if(maxZ<z){
                maxZ=z;
            }else if(z<minZ){
                minZ=z;
            }
            if(maxW<w){
                maxW=w;
            }else if(w<minW){
                minW=w;
            }
        }
    }
    long dz=(long)maxZ-minZ,dw=(long)maxW-minW;
    cout<<((dz<dw)?dw:dz)<<endl;
    
    return 0;
}
