#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    int ans = 0;
    string s, t;
    cin >> s >> t;
    rep(i, 3) {
        if (s[i] == t[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}