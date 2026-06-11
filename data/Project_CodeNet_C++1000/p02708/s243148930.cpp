#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){

    long long N,K;
    cin>>N>>K;

    long long ans=0;
    long long mod=1000000007;
    for(long long i=K;i<=N+1;i++){
        ans+=(N*(N+1)/2-(N-i)*(N-i+1)/2-(i-1)*i/2)+1;
        ans%=mod;
    }
    cout<<ans<<endl;

    return 0;
}