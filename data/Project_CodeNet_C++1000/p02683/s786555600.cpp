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

int c[N];
int mat[13][13];
int temp[13];

void solve () {
    int n,m,x;cin>>n>>m>>x;
    for (int i=0;i<n;i++) {
        cin>>c[i];
        for (int j=0;j<m;j++) {
            cin>>mat[i][j];
            // cout<<mat[i][j]<<" ";
        }
        // cout<<endl;
    }
    int ans = INF;
    // Understaning of all m is greater than x.
    for (int msk=1;msk<(1<<n);msk++) {
        for (int i=0;i<=m;i++) temp[i] = 0;
        int cc = 0;
        for (int j=0;j<n;j++) {
            // Should Take This.
            if (msk & (1<<j)) {
                cc += c[j];
                for (int k=0;k<m;k++) temp[k] += mat[j][k];
            }
        }
        bool ok = true;
        for (int k=0;k<m;k++) {
            if (temp[k] < x) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = min(ans,cc);
        }
    }
    if (ans == INF) ans = -1;
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