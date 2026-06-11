#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    vector<ll> cnt(60);
    rep(i,60){
        rep(j,n){
            if((v[j]>>i)&1) cnt[i]++; 
        }
    }
    ll ans = 0;
    rep(i,60){
        ll now = cnt[i]*(n-cnt[i])%mod;
        rep(j,i){
            now *= 2;
            now %= mod;
        }
        now %= mod;
        ans += now;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}