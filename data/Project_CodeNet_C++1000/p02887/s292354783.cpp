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
    string s;
    cin >> s;

    char lastC = s.at(0);
    string cvtS;

    // 番兵
    s.push_back('A');
    rep(i, n + 1) {
        if(s.at(i) != lastC) {
            cvtS.push_back(s.at(i - 1));
            lastC = s.at(i);
        }
    }

    int ans = cvtS.size();
    cout << ans << endl;

    return 0;
}
