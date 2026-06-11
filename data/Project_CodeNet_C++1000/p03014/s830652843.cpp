#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    ll H, W; cin >> H >> W;
    vector<string> board(H);
    vvll horiz(H, vll(W));
    vvll vert(H, vll(W));
    rep(i, H) cin >> board[i];

    rep(i, H) {
        ll stopper = -1;
        board[i].push_back('#');
        rep(j, W + 1) {
            if (board[i][j] == '#') {
                ll sum = (j - 1) - stopper;
                if (sum > 0) {
                    for (ll k = stopper + 1; k < j; k++) {
                        horiz[i][k] = sum;
                    }
                }
                stopper = j;
            }
        }
        board[i].erase(board[i].begin() + board[i].size() - 1);
    }
    // for (auto elem1 : horiz) {
    //     for (auto elem : elem1) cout << elem << " "; cout << endl;
    // }

    board.push_back(string(W, '#'));
    rep(j, W) {
        ll stopper = -1;
        rep(i, H + 1) {
            if (board[i][j] == '#') {
                ll sum = (i - 1) - stopper;
                if (sum > 0) {
                    for (ll k = stopper + 1; k < i; k++) {
                        vert[k][j] = sum;
                    }
                }
                stopper = i;
            }
        }
    }
    // for (auto elem1 : vert) {
    //     for (auto elem : elem1) cout << elem << " "; cout << endl;
    // }

    ll max_num = 0;
    rep(i, H) rep(j, W) max_num = max(max_num, horiz[i][j] + vert[i][j] - 1);
    cout << max_num << endl;
    return 0;
}