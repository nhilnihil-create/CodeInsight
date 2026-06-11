#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0;i<(int)(n);i++)
using P = pair<int,int>;
// i<j
// j-i=v[i]+v[j]
// j-v[j]=v[i]+i
signed main() {
    int n;cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    map<int,int> mp;
    int ans = 0;
    rep(i, n) {
        ans+=mp[i+1-v[i]];
        mp[i+1+v[i]]++;
    }
    cout << ans << endl;
    return 0;
}