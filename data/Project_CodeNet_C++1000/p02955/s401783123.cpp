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
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;

int main() {
    ll n, k;
    cin >> n >> k;

    vl a(n);
    ll sum = 0;
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }

    vl yakusu;  // sumの約数
    for(ll i = 1; i*i <= sum; i++) {
        if(sum%i == 0) {
            yakusu.pb(i);
            if(i*i != sum) {
                yakusu.pb(sum/i);
            }
        }
    }

    ll ans = 1;
    rep(I, yakusu.size()) {

        ll d = yakusu[I];

        vl r(n);
        rep(i, n) {
            r[i] = a[i]%d;
        }
        sort(all(r));

        ll tot = 0;
        rep(i, n) {
            tot += r[i];
        }
        
        ll l = n - tot/d;
        ll need = 0;
        rep(i, l) {
            need += r[i];
        }
        
        if(need <= k) {
            ans = max(ans, d);
        }
    }

    out(ans);
    re0;
}