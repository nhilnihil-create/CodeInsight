#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
const int MOD=998244353;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;cin >> n >> k;
    vector<ll> a(n),sum(n+1);
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum[i+1]=sum[i]+a[i];
    }
    map<ll,ll> mp;
    for(int i=0;i<=n;i++){
        (sum[i]+=n-i)%=k;
    }
    ll ans=0;
    for(int i=0;i<=n;i++){
        ans+=mp[sum[i]];
        mp[sum[i]]++;
        if(i>=k-1){
            mp[sum[i-k+1]]--;
        }
    }
    cout << ans << endl;
}