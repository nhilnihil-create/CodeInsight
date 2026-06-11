#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    if(n==1) {cout << 1 << endl; return 0;}
    int ans = 1e9;
    rep(i,n) {
        rep(j,n) {
            if(i==j) continue;
            ll dx = x[j] - x[i];
            ll dy = y[j] - y[i];
            int cnt = 0;
            rep(k,n){
                rep(l,n) {
                    if(k==l) continue;
                    if(dx==x[l]-x[k] && dy==y[l]-y[k]) cnt++;
                }
            }
            ans = min(ans, n-cnt);
        }
    }
    cout << ans << endl;
    return 0;
}