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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> p(n, k - q);
    rep(i, q) {
        int a;
        cin >> a;
        --a;
        p[a]++;
    }
    rep(i, n) {
        if (p.at(i) <= 0) puts("No");
        else puts("Yes");
    }
    return 0;
}
