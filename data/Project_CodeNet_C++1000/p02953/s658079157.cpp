#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i]; 
    bool flag = true;

    for (int i = n - 1; i >= 1 ; i--) {
        if (h[i] >= h[i - 1]) continue;
        else if (h[i] == h[i - 1] - 1) h[i - 1] = h[i - 1] - 1;
        else {
            flag = false;
            break;
        }
    }

    if (flag) cout << "Yes";
    else cout << "No";
}
