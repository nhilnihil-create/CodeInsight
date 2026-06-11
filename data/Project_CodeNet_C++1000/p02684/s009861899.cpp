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
typedef vector<ii> vii;
 
const int N = int(2e5)+10;
const int K = 10005;
// const int MOD = int(1e9)+7;
const int INF = int(1e9)+5;
const ll INF64 = 1e18;

const ll MOD = 1e9+7;
inline ll add(ll a, ll b, ll m) { return (((a % m + b % m) % m + m) % m); }
inline ll mul(ll a, ll b, ll m) { return (((a % m * b % m) % m + m) % m); }

vi path;
vvi cycles;
int a[N],visited[N];
bool visited2[N];
int st,c = 0;

void dfs (int s) {
    path.pb(s);
    // Gray Colour.
    visited[s] = 1;
    int to = a[s];
    if (visited[to] != 2) {
        // Enter a gray vertex, cycle found.
        if (visited[to] == 1) {
            cycles.emplace_back();
            int id = sz(path) - 1;
            while (path[id] != to) {
                cycles.back().pb(path[id]);
                id--;
            }
            cycles.back().pb(to);
        } else {
            dfs(to);
        }
    }
    path.pop_back();
    // Black vertex, done and dusted.
    visited[s] = 2;
}

void dfs2 (int s) {
    if (visited2[s]) return;
    visited2[s] = true;
    c++;
    int to = a[s];
    if (to == st) return;
    dfs2(to);
}

int dfs3 (int s,int k) {
    if (k == 0) return s;
    int to = a[s];
    return dfs3(to,k-1);
}

void solve () {
    int n;cin>>n;
    ll K;cin>>K;
    for (int i=1;i<=n;i++) cin>>a[i];
    dfs(1);
    reverse(all(cycles[0]));
    st = cycles[0][0];
    int sze = sz(cycles[0]);
    // Cycle Starts At 1 Itself.
    if (st == 1) {
        K %= sze;
        int ans;
        for (int i=0;i<=K;i++) ans = cycles[0][i];
        cout<<ans<<endl;
    } else {
        dfs2(1);
        if (K >= c) {
            K -= c;
            K %= sze;
            int ans;
            for (int i=0;i<=K;i++) ans = cycles[0][i];
            cout<<ans<<endl;
        } else {
            cout<<dfs3(1,K)<<endl;
        }
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