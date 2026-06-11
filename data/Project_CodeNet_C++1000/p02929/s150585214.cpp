#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

int main(){
    int n;
    string s;
    cin>>n>>s;
    int type[2*n];
    int cnt=0;
    rep(i,2*n){
        type[i]=(i+s[i])%2;
        if(type[i])++cnt;
    }
    if(cnt!=n){
        cout<<0<<endl;
        return 0;
    }
    ll ans=1;
    int sum=0;
    rep(i,2*n){
        if(type[i]=='B'%2){
            ++sum;
        }
        else{
            ans*=sum--;
            ans%=mod;
        }
    }
    for(int i=1;i<=n;++i){
        ans=(ans*i)%mod;
    }
    cout<<ans<<endl;
}
