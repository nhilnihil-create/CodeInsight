#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep1(i, n) for (int i = 1; i <= n; ++i)

int main() {
    string s;
    cin >> s;
    if (s[1] == 'B') {
        cout << s[0] << 'R' << s[2] << endl;
    }
    if (s[1] == 'R') {
        cout << s[0] << 'B' << s[2] << endl;
    }
    return 0;
}