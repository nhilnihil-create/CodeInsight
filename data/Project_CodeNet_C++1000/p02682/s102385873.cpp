#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ff first
#define ss second
#define pb push_back
#define int long long
typedef pair<int,int> pii;

const int mod = 1e9 + 7;
const int MOD = 998244353;
const int N = 5e5 + 5;


void solve(){
    int a, b, c, k; cin >> a >> b >> c >> k;
    int res = 0;
    res += min(a, k);
    k -= min(a, k);
    k -= b;
    if(k > 0){
        res -= k;
    }
    cout << res << endl;
}

int32_t main(){
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for(int T = 1 ; T <= t ; T++){
        // cout << "Case #" << T << ": " << endl;
        solve();
    }
}