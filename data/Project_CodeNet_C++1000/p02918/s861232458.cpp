#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int ans = 0;
    rep(i, n - 1) if (s[i] == s[i + 1]) ans++;

    cout << min(ans + 2 * k, n - 1) << endl;
    return 0;
}
