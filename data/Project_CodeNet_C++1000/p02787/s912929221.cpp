/*
 _ _ _   _    _   _    _   _ _ _   _    _   _ __ _   __       __
|  _ _| | |  | | | |  | | |  _  | | |  | | |  __  | |   \   /   |
| |_ _  | |__| | | |  | | | |_| | | |__| | | |__| | | |\ \_/ /| |
|_ _  | |  __  | | |  | | |  _ <  |  __  | |  __  | | | \   / | |
 _ _| | | |  | | | |__| | | |_| | | |  | | | |  | | | |  \_/  | |  _   _   _
|_ _ _| |_|  |_| |_ __ _| |_ _ _| |_|  |_| |_|  |_| |_|       |_| |_| |_| |_|

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fi first
#define se second
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(a) cout << #a << " = " << a << " ";
#define endl "\n"
const int MOD=1e9 + 7;
const int N=1000100;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){  
                                                        for (auto &v : vec) is >> v; return is; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

void solve(){
    long h,n;
    cin>>h>>n;
    vector<long> a(n),b(n);
    for(int i=0;i<n;i++)
        cin>>a[i]>>b[i];

    vector<ll> dp(h+1,2e9);
    dp[0]=0;
    for(int i=0;i<=h;i++){
        for(int j=0;j<n;j++){
            long to=min(i+a[j],h);
            dp[to]=min(dp[to],dp[i]+b[j]);
        }
    }
    cout<<dp[h]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t = 1;
    // cin>>t;
    for (long int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}