#include<bits/stdc++.h> 
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

const int mod = 998244353;

int main(){
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i, n) cin >> d[i];
    vector<vector<int>> a(n);
    a[0].pb(0);
    rep(i, n){
        if (i == 0 && d[i] != 0){
            cout << 0 << endl;
            return 0;
        }
        if (i && d[i] == 0){
            cout << 0 << endl;
            return 0;
        }
        if (i) a[d[i]].pb(i);
    }
    int p;
    rep(i, n){
        if (a[i].size()) p = i;
    }
    ll ans = 1;
    for(int i = 1; i <= p; i++){
        if (a[i].size() == 0){
            cout << 0 << endl;
            return 0;
        }
        ll q = 1;
        rep(j, a[i].size()) q = (q * a[i - 1].size()) % mod;
        ans = (ans * q) % mod;
    }
    cout << ans << endl;
}