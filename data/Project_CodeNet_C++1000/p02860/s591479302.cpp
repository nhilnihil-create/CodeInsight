#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
using llint = long long int;
using namespace std;

int main() {
    fastIO;
    int n;
    cin >> n;

    string s;
    cin >> s;

    if (n % 2 == 1) {
        cout << "No";
        return 0;
    }

    string left = s.substr(0, n / 2);
    string right = s.substr(n / 2);
    if (left == right)
        cout << "Yes";
    else
        cout << "No";
}