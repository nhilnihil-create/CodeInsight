#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    bool ok = true;
    rep(i, n) {
        cin >> h[i];
        if (i == 0) {
            h[i]--;
            continue;
        }
        if (h[i-1] < h[i]) h[i]--;
        if (h[i] < h[i-1]) {
            ok = false;
            break;
        }
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}