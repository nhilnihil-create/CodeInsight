#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n, m;
    cin >> n >> m;
    vector<bool> ac(n);
    vector<int> wa(n);
    for (int i = 0; i < m; i++) {
        int x; string s;
        cin >> x >> s;
        x--;
        if(s == "WA" && ac[x] == 0) {
            wa[x]++;
        }
        if (s == "AC") {
            ac[x] = 1;
        }
    }
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (ac[i]) {
            a++;
            b+= wa[i];
        }
    }
    cout << a << " " << b;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
