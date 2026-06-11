#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int j, ans = 0;
    string s;
    cin >> s;
    j = s.size() - 1;
    rep(i, s.size()) {
        if (i > j)
            break;
        if (s[i] != s[j])
            ans++;
        j--;
    }
    cout << ans << endl;
    return 0;
}