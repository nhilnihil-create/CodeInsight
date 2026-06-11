#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int n, k, r_point, s_point, p_point;
    cin >> n >> k >> r_point >> s_point >> p_point;
    int point[] = {r_point, s_point, p_point};
    string t;
    cin >> t;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        string s;
        for (int j = i; j < n; j += k) {
            s.push_back(t[j]);
        }
        //cout << s << endl;
        vector<int> u(s.size());
        rep(j,s.size()) {
            if (s[j] == 'r') u[j] = 2;
            if (s[j] == 's') u[j] = 0;
            if (s[j] == 'p') u[j] = 1;
        }
        //cout << u << endl;
        vector<vector<int>> dp(u.size()+1, vector<int>(3));
        for (int ni = 0; ni < u.size(); ni++) {
            for (int nj = 0; nj < 3; nj++) {
                for (int nk = 0; nk < 3; nk++) {
                    if (nj == nk) continue;
                    if (nk == u[ni]) chmax(dp[ni+1][nk], dp[ni][nj] + point[nk]);
                    else chmax(dp[ni+1][nk], dp[ni][nj]);
                }
            }
        }
        int res = 0;
        rep(j,3) chmax(res, dp[u.size()][j]);
        //cout << res << endl;
        ans += res;
    }
    cout << ans << endl;
    return 0;
}