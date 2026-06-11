#include <bits/stdc++.h>
#define repl(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    ll n;
    cin >> n;
    ll s = 0;
    vector<ll> a(n,0);
    rep(i,n){cin >> a[i];s += a[i];}
    ll res = LONG_LONG_MAX;
    ll sum = 0;
    rep(i,n){
        sum += a[i];
        res = min(res,abs(sum - (s - sum)));
    }
    cout << res << endl;
    return 0;
}