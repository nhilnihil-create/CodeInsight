#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
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

int main() {
    string s;
    cin >> s;
    ll n = s.size();

    vvl dp(n+10, vl(3));  // dp[i][j] : i文字目までで最後の分割の文字数がjのときの分割個数の最大値
    dp[1][1] = 1;
    exrep(i, 1, n) {  // i文字目まで分割したとする
        exrep(j, 1, 2) {  // 最後の分割はj文字とする
            exrep(k, 1, 2) {  // 次の分割はk文字にする
                bool ok = true;  // 次の分割が可能ならtrue
                if(j == k) {
                    if(j == 1 && s[i-1] == s[i]) {
                        ok = false;
                    }
                    if(j == 2 && 2 <= i && i < n-1 && s[i-2] == s[i] && s[i-1] == s[i+1]) {
                            ok = false;
                    }
                }
                if(ok) {
                    chmax(dp[i+k][k], dp[i][j] + 1);        
                }
            }
        }
    }

    out(max(dp[n][1], dp[n][2]));
    re0;
}