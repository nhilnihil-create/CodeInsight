#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, l;
    cin >> n >> l;
    vector<int> taste(n);
    int mi = 500;
    rep(i, n) {
        taste[i] = l + i;
        mi = min(abs(taste[i]), mi);
    }

    int ans = 0;
    rep(i, n) {
        if (abs(taste[i]) == mi) continue;
        else ans += taste[i];
    }

    cout << ans << endl;

}