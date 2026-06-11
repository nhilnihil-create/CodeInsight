#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
 
using namespace std;
using T = tuple<int,int,int>;

#define eb emplace_back
#define pb push_back
#define MP make_pair
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i,j,n) for (int i = j; i < n; ++i)
#define repn(i,j,n) for (int i = j; i <= n; ++i)
#define revn(i,j,n) for (int i = j; i >= n; --i)
#define sz(i) i.size()
#define mem(i,v) memset(i,v,sizeof(i))
#define all(v) v.begin(), v.end()
#define endl '\n'
#define int long long
#define INF 1e18
#define ss second
#define ff first

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
 
const int mod=1e9+7;
//const int mod=998244353;
const int up=1e5+10;
const int MAXN=1e6+10;

int a[up],b[up];

void solve()
{
    int m=2019;
    string s;
    cin>>s;
    map<int,int>mp;
    int pw=1,ans=0,now=0;
    mp[0]++;
    revn(i,sz(s)-1,0)
    {
        now+=(s[i]-'0')*pw;
        now%=m;
        pw*=10 ;
        pw%=m;
        ans+=mp[now];
        mp[now]++;
    }
    cout<<ans<<endl;
}


int32_t main()
{
    fast_cin();
    int t;
    // memset(prime, true, sizeof(prime)); 
    // sieve();
    //cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
    //cout<<ans<<endl;
}

