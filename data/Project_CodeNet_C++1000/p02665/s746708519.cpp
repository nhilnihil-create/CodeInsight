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
 
//const int mod=1e9+7;
const int mod=998244353;
const int up=1e5+10;
const int MAXN=1e6+10;

// int n,m,x,y,res=0,sz[2*up],par[2*up],ans[2*up];

// int get(int x)
// {
//     return x*(x-1)/2;
// }

// int find(int x)
// {
//     if(par[x]==x)
//         return x;
//     else
//         return par[x]=find(par[x]);
// }

// void merge(int u,int v)
// {
//     x=find(u);
//     y=find(v);
//     if(sz[x]<sz[y])
//         swap(x,y);
//     res-=get(sz[x]);
//     res-=get(sz[y]);
//     sz[x]+=sz[y];
//     res+=get(sz[x]);
//     par[v]=u;
// }

// void solve()
// {
//     cin>>n>>m;
//     vector<pii>q(m+1);
//     vector<pair<int,pii>>e(n);
//     repn(i,1,n)
//     {
//         sz[i]=1;
//         par[i]=i;
//     }
//     repn(i,1,n-1)
//     {
//         cin>>e[i].ss.ff>>e[i].ss.ss>>e[i].ff;
//     }
//     repn(i,1,m)
//     {
//         cin>>q[i].ff;
//         q[i].ss=i;
//     }
//     sort(all(e));
//     sort(all(q));
//     int pos=1;
//     repn(i,1,m)
//     {
//         while(pos<n && e[pos].ff<=q[i].ff)
//         {
//             x=e[pos].ss.ff;
//             y=e[pos].ss.ss;
//             merge(x,y);
//             ++pos;
//         }
//         ans[q[i].ss]=res;
//     }
//     repn(i,1,m)
//     {
//         cout<<ans[i]<<" ";
//     }
//     cout<<endl;
// }


int dep[2*up],a[2*up];
void solve()
{
    int n;
    cin>>n;
    repn(i,0,n)
    {
        cin>>a[i];
    }
    revn(i,n,0)
    {
        if(i==n)
            dep[i]=a[i];
        else
            dep[i]=dep[i+1]+a[i];
    }
    int cur=1,ans=0;
    repn(i,0,n)
    {
        
        if(cur<0)
        {
            cout<<-1<<endl;
            return;
        }
        //cout<<cur<<" "<<dep[i+1]<<endl;
        ans+=min(cur,dep[i]);
        cur-=a[i];
        cur=cur*2;
        cur=min(cur,((int)1e15));
        if(cur<0)
        {
            cout<<-1<<endl;
            return;
        }
    }
    cout<<ans<<endl;
}

int32_t main()
{
    int t;
    // memset(prime, true, sizeof(prime)); 
    // sieve();
    //cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
}

