#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    string s, t;
    cin >> s >> t;
    for (size_t i = 0; i < s.size(); i++) {
        if (s.at(i) != t.at(i)) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}
