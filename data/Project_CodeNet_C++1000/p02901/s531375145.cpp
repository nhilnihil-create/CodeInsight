#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
const int MAX=1e9;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> b(m);
    vector<int> c(m,0);
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        for(int j = 0; j < b[i]; j++) {
            int tc;
            cin >> tc;
            c[i]|= (1<<(tc-1));
        }
    }

    int dp[(1<<n)];
    for(int i = 0; i < (1<<n); i++) {
        dp[i]=MAX;
    }
    dp[0]=0;

    for(int j = 0; j < m; j++) {
        for(int i = 0; i < (1<<n); i++) {
            int ni = (i|c[j]);
            dp[ni] = min(dp[i]+a[j],dp[ni]);
        }
    }

    int ans=dp[(1<<n)-1];
    if(ans==MAX) ans=-1;
    cout << ans << "\n";

    return 0;
}