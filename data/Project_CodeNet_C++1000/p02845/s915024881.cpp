#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll MOD = 1e9+7;
ll LLINF = 1LL << 60;
int INF = INT_MAX;

int main(){
    ll n; cin>>n;
    vector<ll> a(n);
    rep(i,0,n) cin>>a[i];

    vector<ll> cnt(n+1,0);
    ll ans=1;
    rep(i,0,n){
        if(a[i]!=0) ans=(ans*(cnt[a[i]-1]-cnt[a[i]]))%MOD;
        else ans=(ans*(3-cnt[0]))%MOD;
        cnt[a[i]]++;
    }
    cout<<ans%MOD<<endl;


}