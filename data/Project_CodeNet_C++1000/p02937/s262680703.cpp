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
    string s, t;
    cin >> s >> t;
    ll n = s.size();
    ll m = t.size();

    vvl v(26);
    rep(i, n) {
        v[s[i] - 'a'].pb(i);
    }
    
    ll now = -1;
    ll ans = 0;
    rep(i, m) {
        if(v[t[i] - 'a'].size() == 0) {
            out(-1);
            re0;
        }
        if(upper_bound(all(v[t[i] - 'a']), now) == v[t[i] - 'a'].end()) {
            ans += n;
            now = *v[t[i] - 'a'].begin();
        }  
        else {
            now = *upper_bound(all(v[t[i] - 'a']), now);
        }
    }

    ans += now;
    ans++;

    out(ans);
    re0;
}