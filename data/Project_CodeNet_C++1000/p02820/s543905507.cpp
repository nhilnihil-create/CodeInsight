#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
int main() {
    int n, k, r, s, p;
    string t;
    map<char,int>mp;
    cin >> n >> k >> mp['s'] >> mp['p'] >> mp['r'] >> t;
    vector<vector<char>>v(k);
    rep(i, n){
        v[i%k].push_back(t.at(i));
    }
    int ans = 0;
    rep(i, k){
        char pre = v[i][0];
        int count = 1;
        for (int j = 1; j < v[i].size(); j++) {
            if (pre != v[i][j]) {
                ans += mp[pre]*(int)((count + 1)/2);
                count = 0;
            }
            pre = v[i][j];
            count++;
        }
        ans += mp[pre]*(int)((count + 1 + 1e-5)/2);
        
    }
    cout << ans << endl;
    return 0;
}
