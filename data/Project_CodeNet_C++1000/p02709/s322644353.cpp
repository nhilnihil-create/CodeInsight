
#include <iostream>
#include <functional>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <ctime>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define EPS 1e-8
#define LL_INF 0x3fffffffffffffff
#define INF 0x3f3f3f3f3f3f3f3f
#define MEM(a, b) memset(a, b, sizeof(a))
#define PPER(i, n, m) for (int i = n; i >= m; i--)
#define REPP(i, n, m) for (int i = n; i <= m; i++)
#define REP(i, n, m) for (int i = n; i < m; i++)
#define PER(i, n, m) for (int i = n; i > m; i--)
#define SA(n) scanf("%d", &(n))
#define SLLA(n) scanf("%lld", &(n))
#define MP make_pair
#define FF first
#define SS second
#define PB push_back
#define DE(val) cout << #val << ": " << val << endl;
 
const int dx44[6] = {0, -1, -1, 1, 1};
const int dy44[6] = {0, -1, 1, -1, 1};
const int dx4[6] = {0, 0, 1,-1};
const int dy4[6] = {1, -1, 0,0};
const int dx8[9] = {0, -1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[9] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
const int dx82[9] = {0, -1, -1, 1, 1, 2, 2, -2, -2};
const int dy82[9] = {0, 2, -2, 2, -2, 1, -1, 1, -1};

void update(ll& x,ll v){
    if(x==-1)x=v;
    else if(x>v)x=v;
}
 
ll po(ll a, ll b, ll mod)
{
    ll res = 1;
    a %= mod;
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
ll gcd(ll a, ll b)
{
    if (a == 0)
    {
        return b;
    }
    else
    {
        return gcd(b % a, a);
    }
}
void extgcd(ll a, ll b, ll &d, ll &x, ll &y)
{
    if (!b)
    {
        d = a;
        x = 1;
    }
    else
    {
        extgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}
ll inverse(ll a, ll n)
{
    ll d, x, y;
    extgcd(a, n, d, x, y);
    return d == 1 ? (x + n) % n : -1;
}
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
const int maxn = 2e3 + 15;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
#define mst(x, a) memset(x, a, sizeof(x))
/*************************************************************************/
ll n;
ll val[maxn];
ll dp[maxn][maxn];
std::vector<pair<ll,ll>> v;
ll dfs(int le, int ri,int v_le, int v_ri) {
    if(dp[le][ri] != -1) {
        return dp[le][ri];
    }
    if(le == ri) {
        // abs(le - v[le].second) * v[le].first;
        // cout<<le<<" "<<ri<<" "<<v[le].first<<" "<<dp[le][ri]<<endl;
        return abs(le - v[v_le].second) * v[v_le].first;
    }
    dp[le][ri] = max(v[v_le].first*abs(le-v[v_le].second) + dfs(le+1, ri, v_le+1,v_ri), 
        v[v_le].first*abs(ri-v[v_le].second) + dfs(le, ri-1, v_le+1,v_ri));
    // cout<<le<<" "<<ri<<" "<<dp[le][ri]<<endl;
    return dp[le][ri];
}

void solve() {
    SLLA(n);
    REP(i,0,n) {
        SLLA(val[i]);
        v.push_back(MP(val[i], i));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    memset(dp, -1, sizeof(dp));
    dfs(0,n-1, 0, n-1);

    cout<<dp[0][n-1];
}

int main()
{   
#ifndef ONLINE_JUDGE
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
#endif

    solve();
    // int t;
    // SA(t);
    // REPP(i,1,t) {
    //     printf("Case #%d: ", i);
    //     solve();
    // }
    return 0;
 
}
 