#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ALL(x) x.begin(),x.end()
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define pb(x) push_back(x)
#define eb emplace_back
#define SORT(ls) sort(ls.begin(), ls.end())
#define DESC(ls) sort(ls.rbegin(), ls.rend()) 
#define mp(x, y) make_pair(x, y)
#define INF 1000000000
#define MOD 1000000007
#define F(i, a, n) for(i=a;i<n;i++)
#define SI(x) cin>>x
#define DI(x, y) cin>>x>>y
#define TI(x, y, z) cin>>x>>y>>z
#define FI(w, x, y, z) cin>>w>>x>>y>>z
#define SO(x) cout<<x<<"\n"
#define DO(x, y) cout<<x<<" "<<y<<"\n"
#define TO(x, y, z) cout<<x<<" "<<y<<" "<<z<< "\n"
#define FO(w, x, y, z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<"\n"
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int dp[2002][2002];

int solve(int l, int r, int idx, ii a[], int n)
{
    if(idx == n)
        return 0;
    int &ans = dp[l][r];
    if(ans != -1)
        return ans;
    ans = max(abs(a[idx].second - l)*a[idx].first + solve(l + 1, r, idx + 1, a, n), abs(a[idx].second - r)*a[idx].first + solve(l, r - 1, idx + 1, a, n));   
    return ans;
}

int32_t main(void)
{
    FASTER;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, j;
    int n;
    SI(n);
    ii a[n];
    F(i, 0, n)
        SI(a[i].first);
    F(i, 0, n)
        a[i].second = i;
    sort(a, a + n, greater<ii>());
    memset(dp, -1, sizeof(dp));
    SO(solve(0, n - 1, 0, a, n));
    #ifdef LOCAL
    	cout<<endl<<endl<<"Time: "<<(float)clock()/CLOCKS_PER_SEC<<" seconds"<<endl;
    #endif
    return 0;
}
