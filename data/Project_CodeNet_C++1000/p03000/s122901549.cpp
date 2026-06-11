#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    int c = 0;
    rep(i,n) {
        if (c>x) {
            cout << i << endl;
            return 0;
        }
        c += l[i];
    }
    if (c>x) cout << n << endl;
    else cout << n+1 << endl;
    return 0;
}
