#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> p(n);
    rep (i, n) cin >> p[i];
    int piv = p[0];
    int cnt=0;
    rep (i, n) {
        if (piv >= p[i]) {
            piv = min(piv, p[i]);
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}