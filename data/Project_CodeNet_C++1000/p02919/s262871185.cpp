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

// l[i] - index of element greater than a[i] towards left.
int p[N],l[N],r[N],l2[N],r2[N];
stack<int> st;
vi g[N];

inline void init_stack () {while (!st.empty()) st.pop();}

// Contribution To Sum Technique.
void solve () {
    int n;cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>p[i];
        l[i] = l2[i] =  0;
        r[i] = r2[i] = n+1;
    }
    for (int i=1;i<=n;i++) {
        while (!st.empty() && p[i] > p[st.top()]) st.pop();
        if (!st.empty()) {
            l[i] = st.top();
            g[st.top()].pb(i);
        }
        st.push(i);
    }
    init_stack();
    for (int i=1;i<=n;i++) {
        for (auto v : g[i]) {
            while (!st.empty() && p[v] > p[st.top()]) st.pop();
            if (!st.empty()) {
                l2[v] = st.top();
            }
            st.push(v);
        }
        while (!st.empty() && p[i] > p[st.top()]) st.pop();
        st.push(i);
    }
    init_stack();
    for (int i=n;i>0;i--) {
        g[i].clear();
        while (!st.empty() && p[i] > p[st.top()]) st.pop();
        if (!st.empty()) {
            r[i] = st.top();
            g[st.top()].pb(i);
        }
        st.push(i);
    }
    init_stack();
    for (int i=n;i>0;i--) {
        for (auto v : g[i]) {
            while (!st.empty() && p[v] > p[st.top()]) st.pop();
            if (!st.empty()) {
                r2[v] = st.top();
            }
            st.push(v);
        }
        while (!st.empty() && p[i] > p[st.top()]) st.pop();
        st.push(i);
    }
    // for (int i=1;i<=n;i++) cout<<l2[i]<<" ";cout<<endl;
    // for (int i=1;i<=n;i++) cout<<r2[i]<<" ";cout<<endl;
    ll ans = 0;
    for (int i=1;i<=n;i++) {
        ll t1 = 0,t2 = 0;
        // Left mai greater.
        if (l[i] != 0) {
            t1 = (l[i] - l2[i]) * 1ll * (r[i] - i);
        }
        if (r[i] != n+1) {
            t2 = (r2[i] - r[i]) * 1ll * (i - l[i]);
        }
        // watch(t1);
        // watch(t2);
        ans += (t1+t2) * 1ll * p[i]; 
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

        // left me greater lelo and right me smaller.
        // ll a1 = 0;
        // if (l[i] != 0) {
        //     a1 = (l[i] - l[l[i]]) * 1ll * (r[i] - i);
        // }
        // ll a2 = 0;
        // if (r[i] != n+1) {
        //     a2 = (r[r[i]] - r[i]) * 1ll * (i - l[i]);
        // }
        // watch(a1);
        // watch(a2);
