#include <iostream>
#include <cstdio>
#include <string>
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
const ll MAX_N = 10010;

int main() {
    string s;
    cin >> s;
    
    reverse(all(s));
    s += '0';
    ll n = s.size();
    
    vvl dp(n+10, vl(2, INF));  // dp[i][j] : 下からi桁目まで決めて繰り下がりがj回のときの合計枚数の最小値
    dp[0][0] = 0;
    rep(i, n) {
        rep(j, 2) {
            ll ni = s[i] - '0';
            ni += j;
            rep(ai, 10) {
                ll nj = 0;
                ll bi = ai - ni;
                if(bi < 0) {
                    nj = 1;
                    bi += 10;
                }
                chmin(dp[i+1][nj], dp[i][j] + ai + bi);
            }
        }
    }

    out(dp[n][0]);
    re0;
}