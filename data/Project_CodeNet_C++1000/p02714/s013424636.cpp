#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    ll ans = 0;
    cin >> n;

    string s;
    cin >> s;

    vector<int> r(n, 0), g(n, 0), b(n, 0);
    set<char> temp({'R', 'G', 'B'});
    r[0] = (s[0] == 'R');
    g[0] = (s[0] == 'G');
    b[0] = (s[0] == 'B');
    for (int i = 1; i < n; i++) {
        r[i] = r[i - 1] + (s[i] == 'R');
        g[i] = g[i - 1] + (s[i] == 'G');
        b[i] = b[i - 1] + (s[i] == 'B');
    }


    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            if (s[i] == s[j]) continue;
            set<char> cl = temp;
            cl.erase(s[i]);
            cl.erase(s[j]);
            char left = *cl.begin();
            ll val = 0;
            if (left == 'G') {
                val = g[n - 1] - g[j];
            } else if (left == 'R') {
                val = r[n - 1] - r[j];
            } else {
                val = b[n - 1] - b[j];
            }
            if (j + (j - i) < n && s[j + (j - i)] == left) {
                val--;
            }
            ans += val;
        }
    }
    cout << ans << endl;
}
