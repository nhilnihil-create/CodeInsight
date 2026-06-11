#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (s.at(0) == s.at(1) && s.at(2) == s.at(3) && s.at(1) != s.at(2)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}