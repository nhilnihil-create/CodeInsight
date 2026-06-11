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
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    a--;  b--;  c--;  d--;
    string s;
    cin >> s;
    ll m = s.size();

    exrep(i, a, d-1) {
        if(s[i] == '#' && s[i+1] == '#') {
            out("No");
            re0;
        }
    }
    
    if(c < d) {
        out("Yes");
        re0;
    }
    else if(d < c) {
        exrep(i, b-1, min(m-3, d-1)) {
            if(s[i] == '.' && s[i+1] == '.' && s[i+2] == '.') {
                out("Yes");
                re0;
            }
        }
        out("No");
        re0;
    }
    
    re0;
}