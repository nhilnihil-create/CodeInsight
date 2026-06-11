#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
using namespace __gnu_pbds;
using namespace std;

#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define int               long long
#define INF               1e18
#define ff                first
#define ss                second
#define vi                vector<int>
#define pii               pair<int,int>
#define mii               map<int,int>
#define endl              "\n"
#define GCD(x,y)          (__gcd((x), (y)))
#define LCM(x,y)          (((x)/__gcd((x), (y)))*(y))
#define debug(x)          cout<<#x<<" is "<<(x)<<endl
#define mem(a,x)          memset(a,x,sizeof(a))
#define rep(i,a,b)        for(long long i=a;i<b;i++)
#define sp(ans,p)         fixed <<setprecision(p)<<ans;
#define IOS ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

constexpr int N = 2e5 + 5;
int a[N];
int n;

int cntpec(int len)
{
    int ans = 0;
    rep(i, 0, n)
    {
        if (a[i] > len)
            ans += ((a[i] / len) - (a[i] % len == 0));
    }
    return ans;
}

void solve()
{
    int  k;
    cin >> n >> k;
    // int a[n];
    int maxi = INT_MIN;
    rep(i, 0, n)
    {
        cin >> a[i];
        maxi = (maxi, a[i]);
    }
    int hi = 10e9;                      //this
    int lo = 1;                         //this
    int mid;
    int ans;
    while (lo <= hi)                     //this
    {
        mid = lo + (hi - lo) / 2;
        // debug(mid)
        int z = cntpec(mid);
        // debug(z);
        if (z > k)
        {
            lo = mid + 1;                  //this
        }
        else if (z <= k)
        {
            hi = mid - 1;
            ans = mid;
        }
    }
    cout << ans << endl;
    return;
}

signed main()
{
    IOS;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // sieve();
    int t = 1;
    // cin >> t;
    while (t--)   solve();
    return 0;
}