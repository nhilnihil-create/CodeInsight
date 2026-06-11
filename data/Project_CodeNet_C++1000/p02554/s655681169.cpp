#include <iostream>
using namespace std;
#define MOD 1000000007

int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    
    long s=1,t=1,u=1;
    for(int i=0;i<N;++i){
        s*=10;
        s%=MOD;
        t*=9;
        t%=MOD;
        u*=8;
        u%=MOD;
    }
    int v=(int)((s-2*t+u)%MOD);
    if(v<0){
        v+=MOD;
    }
    cout<<v<<endl;
    
    return 0;
}