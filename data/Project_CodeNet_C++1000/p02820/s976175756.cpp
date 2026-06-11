#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int main() {
    int n, k, r, s, p;
    cin >> n >> k >> r >> s >> p;
    string t;
    cin >> t;
    bool flag[n];
    rep(i, n) flag[i] = true;
    int ans = 0;
    rep(i, k) {
        if (t[i] == 'r')
            ans += p;
        else if (t[i] == 's')
            ans += r;
        else if (t[i] == 'p')
            ans += s;
    }
    for (int i = k; i < n; i++) {
        if (t[i] == t[i - k]) {
            flag[i] = !flag[i - k];
            if (flag[i - k])
                continue;
        }
        if (t[i] == 'r')
            ans += p;
        else if (t[i] == 's')
            ans += r;
        else if (t[i] == 'p')
            ans += s;
    }
    cout << ans << endl;
    return 0;
}
