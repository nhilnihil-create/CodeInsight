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

const int N = int(2e5)+10;
const int K = int(1e6)+10;
// const int MOD = int(1e9)+7;
const int INF = int(1e9)+5;
const ll INF64 = 2e18;

// const ll MOD = 1e9 + 7;
// inline ll add(ll a, ll b, ll m) { return (((a % m + b % m) % m + m) % m); }
// inline ll mul(ll a, ll b, ll m) { return (((a % m * b % m) % m + m) % m); }

int cnt[K],ans[N],f_cnt[K];
ii a[N];

void solve () {
    int n;cin>>n;
    for (int i=1;i<=n;i++) {
        int x;cin>>x;
        a[i] = {x,i};
        f_cnt[x]++;
    }
    int ret = 0;
    for (int i=1;i<=n;i++) {
        int x = a[i].first;
        if (x == 1) {
            if (f_cnt[1] == 1) ret++;
            continue;
        }
        bool ok = true;
        if (f_cnt[1] > 0 || f_cnt[x] > 1)  continue;
        for (int j=2;j*j<=x;j++) {
            if (x%j != 0) continue;
            int num = x/j;
            if (f_cnt[num] || f_cnt[j]) {
                ok = false;
                break;
            }
        }
        ret += ok;
    }
    cout<<ret<<endl;
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