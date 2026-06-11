#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n,k,q;
    cin >> n >> k >> q;
    vector<int> a(n);
    vector<int> b(q);
    rep (i, q) {
        cin >> b[i];
        b[i]--;
    }
    vector<int> d(n);
    rep (i, q)  d[b[i]]++;
    rep (i, n) {
        a[i] = k - q + d[i];
        if (a[i] > 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}