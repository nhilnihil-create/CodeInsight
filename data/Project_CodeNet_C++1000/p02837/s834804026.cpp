#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647 -> 10桁
// MAX ll 9,223,372,036,854,775,807 -> 19桁
// MAX O(n) 10^8 -> 8回
// double pi = M_PI or acos(-1)
// printf("%.10f\n", ans);

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> x(n, vector<int>(0));
    vector<vector<int>> y(n, vector<int>(0));
    rep(i, n) {
        cin >> a.at(i);
        rep(j, a.at(i)) {
            int tmp1, tmp2;
            cin >> tmp1;
            tmp1--;
            x.at(i).push_back(tmp1);
            cin >> tmp2;
            y.at(i).push_back(tmp2);
        }
    }

    int ans = 0;
    for (int bits = 0; bits < (1 << n); bits++) {  // bit pattern
        vector<int> pattern;
        int num = 0;
        for (int i = 0; i < n; i++) {
            int mask = 1 << i;
            if (bits & mask) {  // i番目のbitが立っていれば加算する
                pattern.push_back(1);
                num++;
            } else {
                pattern.push_back(0);
            }
        }

        bool isOk = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < a.at(i); j++) {
                if (pattern.at(i) && pattern.at(x.at(i).at(j)) != y.at(i).at(j)) isOk = false;
            }
        }

        if (isOk) ans = max(ans, num);
    }

    cout << ans << endl;

    return 0;
}
