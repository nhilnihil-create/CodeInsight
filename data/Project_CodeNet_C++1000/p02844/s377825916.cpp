#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define INIT    \
    cin.tie(0); \
    ios::sync_with_stdio(false);

template <class T>
inline bool chmax(T& a, T b) {
    return a = (a < b) ? b : a;
}
template <class T>
inline bool chmin(T& a, T b) {
    return a = (a > b) ? b : a;
}

ll const INF = 1LL << 60;
ll const MOD = 1000000007;

int main() {
    INIT;
    ll N;
    string S;
    cin >> N >> S;

    ll ans = 0;
    rep(i, 1000) {
        string str = "";
        if (i < 10) {
            str = "00" + to_string(i);
        } else if (10 <= i && i < 100) {
            str = "0" + to_string(i);
        } else
            str = to_string(i);

        // cout << str << ":";

        bool flg = true;
        int pos = S.find_first_of(str[0]);
        // cout << str[0] << ", " << pos << " ";
        if (pos == string::npos) {
            flg = false;
        }

        reps(j, 1, 3) {
            // cout << "->" << str[j] << ", ";
            pos = S.find(str[j], pos + 1);
            // cout << pos << ",";
            if (pos == string::npos) {
                flg = false;
                break;
            }
        }
        // cout << endl;

        if (flg) {
            ans++;
            // cout << str << endl;
        } else {
            continue;
        }
    }

    cout << ans << endl;

    return 0;
}