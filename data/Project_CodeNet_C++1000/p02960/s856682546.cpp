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

ll dp[100010][13];
 
int main() {
    string s;
    cin >> s;
    ll m = s.size();

    dp[0][0] = 1;
    rep(i, m) {
        rep(j, 13) {
            if(s[i] == '?') {
                rep(k, 10) {
                    dp[i+1][(10*j + k)%13] += dp[i][j];
                    dp[i+1][(10*j + k)%13] %= mod;
                }
            }
            else {
                ll k = s[i] - '0';
                dp[i+1][(10*j + k)%13] += dp[i][j];
                dp[i+1][(10*j + k)%13] %= mod;
            }
        }
    }
    
    out(dp[m][5]);
    re0;
}