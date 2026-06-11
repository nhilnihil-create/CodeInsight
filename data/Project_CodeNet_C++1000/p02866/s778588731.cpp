#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;
ll mod = 998244353;

int main() {
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i,n) cin >> d[i];
    if(d[0]) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> cnt(n);
    rep(i,n) cnt[d[i]]++;
    if(cnt[0]>1){
        cout << 0 << endl;
        return 0;
    }
    rep(i,n-1){
        if(!cnt[i] && cnt[i+1]) {
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans = 1;
    for(int i = 1; i < n; ++i) {
        if(!cnt[i]) break;
        rep(j,cnt[i]){
            ans*=cnt[i-1];
            ans%=mod;
        }
    }
    cout << ans << endl;
    return 0;
}