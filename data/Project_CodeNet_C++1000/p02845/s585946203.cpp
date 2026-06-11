#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
ll N;
vector<ll> A;
vector<ll> cnt;
ll mod=1e9+7;
int main(void){
    // Your code here!
    cin>>N;
    A.resize(N);
    cnt.resize(N);
    rep(0,i,N)cin>>A[i];
    cnt[0]=3;
    ll ans=1;
    rep(0,i,N){
        if(cnt[A[i]]>0){
            ans*=cnt[A[i]];
            ans%=mod;
            --cnt[A[i]];
            ++cnt[A[i]+1];
        }else{
            cout<<0<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
}
