#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using llint = long long int;
using namespace std;

int main() {
    fastIO;
    string s;
    cin >> s;

    for (size_t i = 0; i < s.size(); i++) {
        if (i % 2 == 0) {
            if (s.at(i) == 'L') {
                cout << "No";
                return 0;
            }
        } else {
            if (s.at(i) == 'R') {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
}