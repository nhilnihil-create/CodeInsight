#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    string s;
    cin >> s;
    if (s == "SUN")
        cout << 7;
    else if (s == "SAT")
        cout << 1;
    else if (s == "FRI")
        cout << 2;
    else if (s == "THU")
        cout << 3;

    else if (s == "WED")
        cout << 4;
    else if (s == "TUE")
        cout << 5;
    else if (s == "MON")
        cout << 6;
}
