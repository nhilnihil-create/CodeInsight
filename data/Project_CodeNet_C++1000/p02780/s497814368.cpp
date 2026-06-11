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
    ll n,k;
    cin>>n>>k;
    ll i,j;
    ll a[n];
    ld sum[n];
    
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
       ll no = a[i]*(a[i]+1);
       no/=2;
       ld tt = 1.0*no;
       tt/=a[i];
       sum[i]=tt;
    //    cout<<sum[i]<<" ";
    }
    ld pre[n];
    pre[0]=sum[0];
    ld maxi=0;
    for(i=1;i<n;i++)
    {
        pre[i]=pre[i-1]+sum[i];
    }
    if(k==n)
    {
        cout<<pre[n-1]<<"\n";
        return;
    }
    for(i=k;i<n;i++)
    {
        ld tans = pre[i]-pre[i-k];
        maxi=max(maxi,tans);
    }
    cout<<fixed<<maxi<<"\n";

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