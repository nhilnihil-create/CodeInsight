#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> p(n);
    rep(i, q) {
        int a;
        cin >> a;
        p[a - 1] = p[a - 1] + 1;
    }
    // cout << k - (q - p[i]);
    rep(i, n) {
        if(p[i] + k - q > 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}