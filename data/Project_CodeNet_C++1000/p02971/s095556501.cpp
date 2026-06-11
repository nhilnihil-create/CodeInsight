#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    rep(i, n) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    rep(i, n) {
        if (a[i] != b[0]) {
            cout << b[0] << endl;
        } else {
            cout << b[1] << endl;
        }
    }
    return 0;
}