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

    ll s[m],c[m];
    ll a[n];
    memset(a,-1,sizeof(a));
    ll i,j;
    for(i=0;i<m;i++)
    {
       cin>>s[i]>>c[i];
       s[i]--;
    }
    
    for(i=0;i<m;i++)
    {
        if(a[s[i]]>=0)
        {
            if(c[i]!=a[s[i]])
            {
                cout<<"-1\n";
                return;
            }
        }
        else{
           a[s[i]]=c[i];
        }
    }
    if(n==1)
    {
        if(a[0]==-1)
        {
            cout<<"0\n";
            return;
        }
    }
    ll f=0;
    for(i=0;i<n;i++)
    {
        if(a[i]>0)
        {
            f=1;
        }
        if(!f)
        {
            if(a[i]==0&&n>1)
            {
                cout<<"-1\n";
                return;
            }
        }
        if(a[i]==-1)
        {
            if(f)
            {
                a[i]=0;
            }
            else{
                a[i]=1;
                f=1;
            }
        }
    }

    for(i=0;i<n;i++)cout<<a[i];
    

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