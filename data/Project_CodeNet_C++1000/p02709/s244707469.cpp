#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

#define int long long int
#define pb push_back
#define M 1000000007
#define inf 10000000000
#define ff first
#define ss second
#define deb(x) cout< #x< " "< x< endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<=n;i++)
#define FORR(a,b,c) for(int a= b;a>=c;a--)
#define fa(arrr) for(auto x:arrr)
#define iPair pair<int, pair<int,int>>
#define sz size()
// #define mp make_pair
#define mxm3(a,b,c) max(a, max(b,c))
#define mi3(a,b,c) min(a, min(b,c))
#define mxn 100005
#define PII pair<int,int>
#define all(v) v.begin(), v.end()
#define endl "\n"
#define N 2005
#define C 4
#define nfs ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
// Ordered Set Tree
// typedef tree<PII, null_type, less<PII>,
//         rb_tree_tag,
//         tree_order_statistics_node_update>
//         oset;
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = (res * x) % M;
        y = y >> 1;
        x = (x * x) % M;
    }
    return res;
}

// int y = 1;

int a[400005], pre[400005], pre2[400005];
// int maxProfit(int *price, int start, int end, int n) {
//     int y = n - (end - start + 1) + 1;
//     if (dp[start][end] != -1) return dp[start][end];
//     if (start > end) {
//         return dp[start][end] = 0;
//     }
//     if (start == end) {
//         return dp[start][end] =  y * price[start];
//     }
//     return dp[start][end] = max(y * price[start] + maxProfit(price, start + 1, end, n), y * price[end] + maxProfit(price, start, end - 1, n));

// }

int h, l, r, n;
// int cnt = 0;
PII arr[N];
int dp[2005][2005];
// int dp;
int go(int l, int r, int i) {
    if (l > r) return 0;
    if(dp[i][l]!=-1) return dp[i][l];
    int c1 = go(l + 1, r, i + 1) + arr[i].ff * abs(arr[i].ss - l);
    int c2 = go(l, r - 1, i + 1) + arr[i].ff * abs((r - arr[i].ss));
    int &cnt = dp[i][l];
    cnt = max(c1, c2);
    return cnt;
}


// (ele + prev)%h >= l
// (ele + prev)%h <= r

// ele , ele-1

void solve() {
    cin >> n;
    // int arr[n + 1];
    // arr[0] = 0;

    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++){
        cin >> arr[i].ff;
        arr[i].ss = i;
    }
    sort(arr, arr+n);
    reverse(arr, arr+n);
    cout << go(0, n-1, 0) << endl;
}



int32_t main()
{


    nfs;
    int t;
    // facto();
    // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }

    return 0;
}