#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, cnt = 0;
    cin >> n;
    vector<int> p(n), a(n);
    rep(i,n) cin >> p[i];

    for (int i = 1; i <= n; i++) a[i-1] = i;

    rep(i,n) {
        if(p[i] != a[i]) cnt++;
    }

    if (cnt == 2 || cnt == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

}
