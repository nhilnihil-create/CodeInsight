#include <bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define ll  long long
#define PR  pair<int, int>

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const long long INF = 5e18;
const double PI = 2 * acos(0.0);
//template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

string s, ans = "";
int dp[N][5];

int fun(int pos, int lst) {
    if (pos == s.size()) {
        return 0;
    }
    int &tmp = dp[pos][lst];
    if (tmp != -1) {
        return tmp;
    }
    tmp = 0;
    if (s[pos] == '?') {
        int x = (lst == 1) + 1 + fun(pos + 1, 2);
        int y = fun(pos + 1, 2);
        tmp += max(x, y);
    } else if (s[pos] == 'D') {
        tmp += ((lst == 1) + 1 + fun(pos + 1, 2));
    } else {
        tmp += fun(pos + 1, 1);
    }
    return tmp;
}

void makeAnswer(int pos, int lst, int cnt) {
//    cout << pos << " " << ans << " " << cnt << endl;
    if (pos == s.size()) {
        return;
    }
    if (s[pos] == '?') {
        if (fun(pos + 1, 1) == cnt) {
            ans += 'P';
            makeAnswer(pos + 1, 1, cnt);
        } else {
            ans += 'D';
            makeAnswer(pos + 1, 2, cnt - 1 - (lst == 1));
        }
    } else if (s[pos] == 'D') {
        ans += s[pos];
        makeAnswer(pos + 1, 2, cnt - 1 - (lst == 1));
    } else {
        ans += s[pos];
        makeAnswer(pos + 1, 1, cnt);
    }
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    cin >> s;
    memset(dp, -1, sizeof dp);
//    cout << fun(0, 0) << '\n';
    int cnt = fun(0, 0);
    makeAnswer(0, 0, cnt);
    cout << ans << '\n';
    return 0;
}
