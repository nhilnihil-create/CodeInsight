#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip> 
#include <algorithm>
#include <queue>
#include <list>
#include <numeric>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

#define sz(a) int((a).size())
#define all(x) x.begin(), x.end()
#define pb push_back
#define endl '\n'
#define watch(x) cout << #x << " : " << x << endl;

#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;

const int N = int(2e3)+10;
const int K = int(1e6)+10;
// const int MOD = int(1e9)+7;
const int INF = int(1e9)+5;
const ll INF64 = 2e18;

const ll MOD = 1e9+7;
inline ll add(ll a, ll b, ll m) { return (((a % m + b % m) % m + m) % m); }
inline ll mul(ll a, ll b, ll m) { return (((a % m * b % m) % m + m) % m); }

int s[N],t[N];
ll dp[N][N],preSum[N][N];

void solve () {
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>s[i];
    for (int i=1;i<=m;i++) cin>>t[i];
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (s[i] == t[j]) dp[i][j] = add(1,preSum[i-1][j-1],MOD);
            else dp[i][j] = 0ll;
            preSum[i][j] = add(preSum[i-1][j],add(preSum[i][j-1],add(MOD-preSum[i-1][j-1],dp[i][j],MOD),MOD),MOD);
        }
    }
    ll ans = 1;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            ans = add(ans,dp[i][j],MOD);
        }
    }
    cout<<ans<<endl;
}

int main () {
    FastIO
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int t;
    // cin>>t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}