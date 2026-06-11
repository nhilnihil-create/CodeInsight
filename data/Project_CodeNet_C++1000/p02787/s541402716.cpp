#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)

int main() {
    ll ans, n,h ;
    ans = 0;
    cin >> h >> n;
    vector<vector<int>> v(n,vector<int>(2));
    int minB = 1e5;
    int minId;
    rep(i, n) {
        cin >> v[i][0] >> v[i][1];
        if (v[i][1] < minB) {
            minB = v[i][1];
            minId = i;
        }
    }
    //cout << minId << ',' << minB << endl;
    vector<int> y(h + 1, v[minId][1]);
    y[0] = 0;
    for (int i = v[minId][0] + 1; i <= h; i++) {
        int m = 1e8;
        bool f = true;
        rep(j, n){
            f = false;
            if (i - v[j][0] >= 0) {
                m = min(m, y[i - v[j][0]] + v[j][1]);
            }else {
                m = min(m, v[j][1]);
            }
        }
        if (f) {
            m = 0;
        }
        y[i] = m;
    }
    

    cout << y[h] << endl;
    return 0;
}

