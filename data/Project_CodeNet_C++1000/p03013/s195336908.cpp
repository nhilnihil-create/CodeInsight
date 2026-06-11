
#include <iostream>
#include <cmath>
#include <algorithm>

#define rep(i,n) for(int i=0;i< (n);++i)
typedef long long ll;

using namespace std;

const int mod=1000000000+7;


int main() {
    
    int N,M;
    cin>>N>>M;
    
    int A[N+1];
    
    for(int i=0;i<=N;++i){
        A[i]=1;
    }

    int a;
    int p=-1;
    
    for(int i=1;i<=M;++i){
        cin>>a;
        if(p==a){cout<<0<<endl;return 0;}
        A[a]=0;
        p=a;
    }
    
    ll d[N+1];
    for(int i=0;i<=N;++i){
        d[i]=0;
    }
    d[0]=1;
    
    for(int i=1;i<=N;++i){
        
        if(A[i]==0)continue;
        if(i==1){
            d[i]=d[i-1];
        }else{
            d[i]=(d[i-1]+d[i-2])%mod;
        }
        
    }
    
    cout<<d[N]<<endl;
   
}
