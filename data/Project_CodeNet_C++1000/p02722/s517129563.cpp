#include<iostream>
#include<cmath>
using namespace std;
long long N,N_,n,ans=0LL;
int main(void){
    cin>>N;
    if(N==2){cout<<1<<endl;return 0;}
    N_=N-1LL;
    for(long long K=2LL;K<=sqrt(N_);K++)if(N_%K==0LL)ans+=1LL+(K!=sqrt(N_));
    for(long long K=2LL,k;K<=sqrt(N);K++){
        if(N%K==0LL){
            n=N;
            while(n%K==0LL)n/=K;
            ans+=(n%K==1LL);
            if(K==sqrt(N))continue;
            n=N;
            k=N/K;
            while(n%k==0LL)n/=k;
            ans+=(n%k==1LL);
        }
    }
    cout<<ans+2LL<<endl;
    return 0;
}