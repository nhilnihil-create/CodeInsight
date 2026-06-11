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
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> o_tree;


void solve()
{
   ll n,m;
   cin>>n>>m;
   ll a[m],b[m];

   ll i,j,k;
   vll v[m];
   for(i=0;i<m;i++)
   {
       cin>>a[i]>>b[i];
       for(j=0;j<b[i];j++)
       {
          ll x;
          cin>>x;
          v[i].pb(x);
       }
   }

   ll bitmax =(1ll<<n);
   bitset<60> bb[m];
   for(i=0;i<m;i++)
   {
       for(auto it:v[i])
       {
           bb[i][it-1]=1;
       }
   }
//    for(i=0;i<m;i++)
//    {
//        cout<<bb[i]<<"\n";
//    }
   ll res = 1e18;

   ll dp[bitmax];
   for(i=0;i<bitmax;i++)
   {
      dp[i]=1e18;
   }
   ll noo[m];
   dp[0]=0;
   for(i=0;i<m;i++)
   {
    //    cout<<bb[i]<<"\n";
       ll no =bb[i].to_ullong();
       noo[i]=no;
    //    cout<<no<<"--\n";
       dp[no]=min(dp[no],a[i]);
   }
   
   for(i=0;i<bitmax;i++)
   {
       for(j=0;j<m;j++)
       {
           if((noo[j]|i)!=i)
           {
               dp[i|noo[j]]=min(dp[noo[j]|i],dp[i]+a[j]);
           }
       }
   }

   res=dp[bitmax-1];
   if(res==1e18)
   {
       cout<<"-1\n";
       return;
   }
   cout<<res<<"\n";
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);


if (fopen("input.txt","r" ))
  {
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
  }
cout<<setprecision(20);


ll t=1;


// cin>>t;


while(t--)
{
solve();
} 


return 0;
}