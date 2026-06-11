#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
int res, n;
string s;
int main() {
    DAU
    cin >> s;
    n = static_cast<int>(s.size());
    s = '$' + s;
    for (size_t i = 1; i <= n / 2; ++i)
        res += (s[i] != s[n - i + 1]);
    cout << res;
    PLEC
}
