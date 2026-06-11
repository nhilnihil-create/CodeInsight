#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define mp make_pair
#define pb(x) push_back(x)
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pcc pair<char, char>
#define pdd pair<double, double>
#define mll map<long long, long long>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define flsh fflush(stdout)
#define gcd __gcd
#define clr(x) memset(x, 0, sizeof(x))
#define mod 1000000007LL
#define mod2 998244353LL
#define INF 1000000000007

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> o_tree;

void solve()
{
   ll h,w,n;
   cin>>h>>w>>n;
   map<pll,ll> m;
   ll i,j;
   ll row[h+1],col[w+1];
   clr(row);
   clr(col);
   ll res=0;
   for(i=0;i<n;i++)
   {
       ll x,y;
       cin>>x>>y;
       m[mp(x,y)]++;
       row[x]++;
       col[y]++;
   }
    
   vector<pll> roww,coll;
   for(i=0;i<=h;i++)
   {
      roww.pb(mp(row[i],i));
   }
   for(i=0;i<=w;i++)
   {
      coll.pb(mp(col[i],i));
   }
   sort(roww.rbegin(),roww.rend());
   sort(coll.rbegin(),coll.rend());
   ll maxr = roww[0].first;
   ll maxc = coll[0].first;
   res = maxr+maxc-1;
   ll count=0;
   for(i=sz(roww)-1;i>=0;i--)
   {
       if(roww[i].first!=maxr)
       {
           roww.erase(roww.begin()+i);
       }
   }
     for(i=sz(coll)-1;i>=0;i--)
   {
       if(coll[i].first!=maxc)
       {
           coll.erase(coll.begin()+i);
       }
   }
   for(auto i:roww)
   {
       ll f=0;
       for(auto j:coll)
       {
           if(m.find(mp(i.second,j.second))==m.end()){
           f=1;
           ll tans = i.first+j.first;
           res=max(res,tans);
           break;
           }
       }
       if(f)
       {
           break;
       }
   }
   cout<<res<<"\n";




}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    cout << setprecision(20);

    ll t = 1;

    // cin>>t;

    while (t--)
    {
        solve();
    }

    return 0;
}
