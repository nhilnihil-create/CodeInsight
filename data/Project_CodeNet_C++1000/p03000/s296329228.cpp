#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> d(n + 1);
    vector<int> l(n);

    rep(i, n) {
        cin >> l[i];
        d[i + 1] = d[i] + l[i]; 
    }

    int ans = 0;
    rep(i, n + 1) {
        if (d[i] <= x) ans++;
        else break;
    }

    cout << ans << endl;
}