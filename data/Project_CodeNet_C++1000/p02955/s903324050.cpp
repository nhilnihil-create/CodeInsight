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

// nの約数を降順に列挙したvectorを返す。計算量はO(√n)
vector<ll> yakusu(ll n) {
    vl res;
    for(ll i = 1; i*i <= n; i++) {
        if(n%i == 0) {
            res.pb(i);
            if(i != n/i) {
                res.pb(n/i);
            }
        }
    }
    sort(rall(res));
    return res;  
}
 
int main() {
    ll n, k;
    cin >> n >> k;

    vl a(n);
    ll sum = 0;
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }

    vl AAA = yakusu(sum);

    for(auto d : AAA) {
        vl v(n);
        rep(i, n) {
            v[i] = a[i]%d;
        }
        sort(all(v));
        rep(x, n) {
            ll cnt = 0;
            exrep(i, 0, x) {
                cnt += v[i];
            } 
            if(cnt > k) {
                continue;
            }
            cnt = 0;
            exrep(i, x+1, n-1) {
                cnt += d - v[i];
            }
            if(cnt <= k) {
                out(d);
                re0;
            }
        }
    }
    
    re0;
}