#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
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

const int MAX_GRID = 2001;
int wide[MAX_GRID][MAX_GRID], height[MAX_GRID][MAX_GRID];

int main() {
    int H, W; cin >> H >> W;
    string S[H]; rep(i, H)  cin >> S[i];
    rep(i, H) {
        int cnt = 1;
        rep(j, W) {
            if(S[i][j] == '#') wide[i][j] = 0, cnt = 1;
            else wide[i][j] = cnt, ++cnt;
        }
        for(int j = W - 1; j > 0; --j) {
            if(wide[i][j - 1] == 0 || wide[i][j] == 0)continue;
            wide[i][j - 1] = wide[i][j];
        }
    }
    rep(j, W) {
        int cnt = 1;
        rep(i, H) {
            if(S[i][j] == '#') height[i][j] = 0, cnt = 1;
            else height[i][j] = cnt, ++cnt;
        }
        for(int i = H - 1; i > 0; --i) {
            if(height[i - 1][j] == 0 || height[i][j] == 0)continue;
            height[i - 1][j] = height[i][j];
        }
    }
    int ans = 0;
    rep(i, H) {
        rep(j, W) {
            ans = max(ans, height[i][j] + wide[i][j] - 1);
        }
    }
    cout << ans << endl;
}
