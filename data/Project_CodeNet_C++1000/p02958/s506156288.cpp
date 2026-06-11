#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i != p[i-1]) cnt++;
    }
    if (cnt <= 2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
