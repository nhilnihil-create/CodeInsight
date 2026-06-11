#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void solve() {
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i, n) {
        int d1, d2;
        cin >> d1 >> d2;
        d[i] = d1 == d2;
    }

    rep(i, n-2) {
        if (d[i] == true && d[i] == d[i+1] && d[i] == d[i+2]) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main() {
    solve();
    return 0;
}
