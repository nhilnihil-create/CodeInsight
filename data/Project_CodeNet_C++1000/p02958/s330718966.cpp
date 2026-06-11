#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    vector<int> sortp(n);
    rep(i, n) sortp[i] = p[i];
    sort(sortp.begin(), sortp.end());
    
    rep(i, n) {
        if (sortp[i] != p[i]) break;
        if (i == n-1) {
            cout << "YES" << endl;
            return 0;
        }
    }

    bool ok = false;
    rep(j, n)rep(i, j) {
        swap(p[i], p[j]);
        rep(k, n) {
            if (sortp[k] != p[k]) break;
            if (k == n-1) {
                cout << "YES" << endl;
                return 0;
            }
        }        
        swap(p[i], p[j]);
    }
    cout << "NO" << endl;

    return 0;
}