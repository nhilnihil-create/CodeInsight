#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)

int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    vector<vector<pair<int, bool>>>q(n,vector<pair<int,bool>>(0));
    rep(i, n){
        cin >> a[i];
        rep(j, a[i]){
            int X;
            bool Y;
            cin >> X >> Y;
            X--;
            q[i].push_back(make_pair(X, Y));
        }
    }
    
    int ans = 0;
    for (int bit = 0; bit < (1<<n); ++bit) {
        bool ok = true;
        int num = 0;
        int f = bit;  //正直者
        rep(i, n){
            if (f & (1<<i)) { //iが正直者なら
                num++;
                for (pair<int,bool> p : q[i]) {
                    if (((f & (1 << p.first)) ^ (p.second << p.first)) != 0) {
                        ok = false;
                    }
                }
            }
        }
        if (ok) {
            ans = max(ans, num);
        }
    }
    cout << ans << endl;
    return 0;
}
