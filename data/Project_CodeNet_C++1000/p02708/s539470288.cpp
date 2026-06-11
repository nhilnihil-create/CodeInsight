#include<iostream>
#include<algorithm>
using namespace std;
const long long MOD=1e9+7;

int main(){
    long long N,K;
    cin>>N>>K;
    long long ans=0;
    for(long long i=K;i<=N+1;++i){
        long long m=i*(i-1)/2;
        long long M=i*(2*N-i+1)/2;
        ans+=M-m+1;
        ans%=MOD;
    }

    cout<<ans<<endl;
}