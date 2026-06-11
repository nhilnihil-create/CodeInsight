#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;
 
int main() {
    ll n, k;
    cin >> n >> k;

    vl a(n);
    rep(i, n) {
        cin >> a[i];
    }

    vl mae(n);  // a[i]より前にあるa[i]より小さい数の個数
    vl ushiro(n);  // a[i]より後ろにあるa[i]より小さい数の個数
    rep(i, n) {
        exrep(j, 0, i-1) {
            if(a[j] < a[i]) {
                mae[i]++;
            }
        }
    }
    rep(i, n) {
        exrep(j, i+1, n-1) {
            if(a[j] < a[i]) {
                ushiro[i]++;
            }
        }
    }
    
    ll ans = 0;
    rep(i, n) {
        ll x = (k*(k+1)/2)%mod;
        ans += (ushiro[i]*x)%mod;
        ans %= mod;
    }
    rep(i, n) {
        ll x = (k*(k-1)/2)%mod;
        ans += (mae[i]*x)%mod;
        ans %= mod;
    }
    
    out(ans);
    re0;
}