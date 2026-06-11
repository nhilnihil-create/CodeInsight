#include <iostream>
#include <vector>

long long pow(long long a,long long b,long long mod){
    if(b==0){
        return 1;
    }else{
        if(b%2==0){
            return pow((a*a)%mod,b/2,mod);
        }else{
            return (pow((a*a)%mod,b/2,mod)*a)%mod;
        }
    }
}

int main(){
    using namespace std;
    int N,K;
    cin>>N>>K;

    long long ans=0;
    long long mod=1000000007;
    long long a;
    vector<long long> m(K+1);
    for(int i=1;i<=K;i++){
        a=K/i;
        m[i]=pow(a,N,mod);
    }
    for(int i=K/2;i>=1;i--){
        for(int j=2*i;j<=K;j+=i){
            m[i]-=m[j];
        }
    }

    for(int i=1;i<=K;i++){
        ans+=i*m[i];
        ans%=mod;
    }

    cout<<ans<<endl;

    return 0;
}