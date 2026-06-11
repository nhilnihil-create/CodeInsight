#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll n,k; cin>>n>>k;
    vector<ll> a(n),partsum(n+1,0);
    rep(i,n){
        ll x; cin>>x; a[i]=x%k;
        partsum[i+1]=a[i];
        partsum[i+1]+=partsum[i];
        partsum[i+1]%=k;
    }
    rep(i,n+1){
        partsum[i]-=i;
        if(partsum[i]<0){
            partsum[i]+=(abs(partsum[i]/k)+1)*k;
        }
        partsum[i]%=k;
    }
    //sort(partsum.begin(),partsum.end());
    ll ans=0;
    map<ll,ll> cnt;
    if(k==1){cout<<0<<endl; return 0;}
    rep(i,min(k,n+1))cnt[partsum[i]]++; 
    rep(i,n+1){
      	ans+=cnt[partsum[i]]-1;
        cnt[partsum[i]]--;
        if(i+k<n+1)cnt[partsum[i+k]]++;
    }
    cout<<ans<<endl;
    return 0;
}