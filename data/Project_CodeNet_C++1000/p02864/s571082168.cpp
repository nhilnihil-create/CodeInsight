#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> h(n),comph(n),rmph(n+1);
    for (int i = 0;i < n;++i) cin >> h[i];
    map<int,int> mp;
    for (int i = 0;i < n;++i) mp[h[i]] = 0;
    mp[0] = 0;
    {
        int i = 0;
        for (auto& p : mp) {
            p.second = i;
            rmph[i] = p.first;
            i++;
        }
    }
    for (int i = 0;i < n;++i) comph[i] = mp[h[i]];
    int s = mp.size();
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(k+1,vector<ll>(s,1LL<<60)));
    dp[0][0][0] = 0;
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < k+1;++j) {
            int t = comph[i];
            for (int l = t;l < s;++l) dp[i+1][j][t] = min(dp[i+1][j][t],dp[i][j][l]);
            for (int l = 0;l < comph[i];++l) dp[i+1][j][t] = min(dp[i+1][j][t],dp[i][j][l]+h[i]-rmph[l]);
        }
        for (int j = 0;j < k;++j) for (int l = 0;l < s;++l) dp[i+1][j+1][l] = min(dp[i+1][j+1][l],dp[i][j][l]);
    }
    ll ans = 1LL<<60;
    for (int i = 0;i < k+1;++i) for (int j = 0;j < s;++j) ans = min(ans,dp[n][i][j]);
    cout << ans << endl;
}