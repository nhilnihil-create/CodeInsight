#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647 -> 10桁
// MAX ll 9,223,372,036,854,775,807 -> 19桁
// MAX O(n) 10^18 -> 18回
// double pi = M_PI or acos(-1)
// printf("%.10f\n", ans);

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> ac(n), pena(n);
    rep(i, m) {
        int p;
        string s;
        cin >> p >> s;
        p--;
        if (ac.at(p)) continue;
        if (s == "AC") {
            ac.at(p) = 1;
        } else {
            pena.at(p)++;
        }
    }

    int AC = 0, PENA = 0;
    rep(i, n) {
        AC += ac.at(i);
        if(ac.at(i)) PENA += pena.at(i);
    }

    cout << AC << " " << PENA << endl;

    return 0;
}
