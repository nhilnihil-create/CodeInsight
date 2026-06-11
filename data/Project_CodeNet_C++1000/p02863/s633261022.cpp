#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

//used[j][i] : j分での最大値を達成するために，種類iの食べ物を使っているか？
// dp[i][j] : i種類目までの料理を見た時，j分以降での美味しさの最大値

int main() {
    int N, T; cin >> N >> T;
    P dish[N]; rep(i, N) cin >> dish[i].first >> dish[i].second;
    vector<vector<int>> dp0N(N + 10, vector<int>(T + 10, 0));
    rep(i, N) {
        rep(j, T) {
            dp0N[i + 1][j] = dp0N[i][j];
            if(dish[i].first <= j) {
                dp0N[i + 1][j] = max(dp0N[i][j], dp0N[i][j - dish[i].first] + dish[i].second);
            }
        }
    }
    vector<vector<int>> dpN0(N + 10, vector<int>(T + 10, 0));
    for(int i = N - 1; i >= 0; --i) {
        rep(j, T) {
            dpN0[i + 1][j] = dpN0[i + 2][j];
            if(dish[i].first <= j) {
                dpN0[i + 1][j] = max(dpN0[i + 2][j], dpN0[i + 2][j - dish[i].first] + dish[i].second);
            }
        }
    }
    int ans = max(dp0N[N][T - 1], dpN0[1][T - 1]);
    rep(i, N) {
        rep(j, T) {
            ans = max(ans, dp0N[i][j] + dpN0[i + 2][T - 1 - j] + dish[i].second);
            //dp0N[3][j] -> 0 -> 3までみたやつ
            //dpN0[3][j] -> N -> 3までみたやつ
        }
    }
    cout << ans << endl;
}
