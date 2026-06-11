#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
const int MOD = 1e9 + 7;
int main() {
    int n;
    cin >> n;
    map<int, vector<int>>t;
    vector<pair<int, int>>e(n - 1, pair<int, int>());
    map<ll, int> c;
    int a, b;
    //cout << '!';
    rep(i, n - 1) {
        cin >> a >> b;
        t[a - 1].push_back(b - 1);
        e[i].first = a - 1;
        e[i].second = b - 1;
    }
    //cout << '!';
    int k = 0;
    int cs = 1;
    vector<int>cr(n, -1);
    for (int s : t[0]) {
        if (cr[0] == cs) {
            cs++;
        }
        c[0*1e6 + s] = cs;
        cr[s] = cs;
        cs++;
    }
    cs--;
    k = max(k, cs);
    //cout << '!';
    rep(i, n){
        cs = 1;
        for (int s : t[i]) {
            if (cr[i] == cs) {
                cs++;
            }
            c[i*1e6 + s] = cs;
            cr[s] = cs;
            cs++;
        }
        cs--;
        k = max(k, cs);
    }
    cout << k << endl;
    rep(i, n - 1){
        cout << c[e[i].first*1e6 + e[i].second] << endl;
    }
    return 0;
}
