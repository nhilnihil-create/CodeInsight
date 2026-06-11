#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n,0);
    rep(i,n)cin >> a[i];
    ll res = 0;
    rep(i,n){
        ll right = 0;
        ll all = 0;
        repp(j,i,n)if(a[i] > a[j])right++;
        rep(j,n)if(a[i] > a[j])all ++;
        res += right * k % MOD;
        res %= MOD;
        res += (k - 1) * k / 2 % MOD * all % MOD;
        res %= MOD;
    }
    cout << res  << endl;
    return 0;
}