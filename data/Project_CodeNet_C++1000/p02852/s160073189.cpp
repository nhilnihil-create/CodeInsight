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

const int N = int(1e5)+10;
const int K = int(1e6)+10;
// const int MOD = int(1e9)+7;
const int INF = int(1e9)+5;
const ll INF64 = 2e18;

const ll MOD = 998244353;
inline ll add(ll a, ll b, ll m) { return (((a % m + b % m) % m + m) % m); }
inline ll mul(ll a, ll b, ll m) { return (((a % m * b % m) % m + m) % m); }

int dp[N],parent[N];
vi ans;

void solve () {
    int n,m;cin>>n>>m;
    string s;cin>>s;
    deque<ii> q;
    if (s[0] == '1' || s[n] == '1') {
        cout<<-1<<endl;
        return;
    }
    // Base Case.
    for (int i=1;i<=n;i++) dp[i] = INF;
    dp[0] = 0;
    q.pb({0,0});
    int l = 0;
    for (int i=1;i<=n;i++) {
        // Whether to kick out or not.
        if (!q.empty() && i >= m+1) {
            if (q.front().first == dp[l]) q.pop_front();
            l++;
        }
        if (s[i] == '1') continue;
        if (!q.empty()) {
            dp[i] = q.front().first + 1;
            parent[i] = q.front().second;
        }
        while (!q.empty() && dp[i] < q.back().first) q.pop_back();
        q.push_back({dp[i],i});
    }
    if (dp[n] == INF) {
        cout<<-1<<endl;
        return;
    }
    int curr = n;
    while (curr != 0) {
        ans.pb(curr);
        curr = parent[curr];
    }
    reverse(all(ans));
    int si = sz(ans);
    for (int i=0;i<si;i++) {
        if (i == 0) cout<<ans[i]-0<<" ";
        else cout<<ans[i]-ans[i-1]<<" ";
    }
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