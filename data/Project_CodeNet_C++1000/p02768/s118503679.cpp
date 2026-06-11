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




long long power(long long x, long long y, long long p)
{
long long res = 1;


x = x % p;


while (y > 0)
{
if (y & 1)
res = (res*x) % p;


y = y>>1;
x = (x*x) % p;
}
return res;
}

long long modInverse(long long n, long long p)
{
return power(n, p-2, p);
}



void solve()
{
    ll n,a,b;
    cin>>n>>a>>b;

    ll res = power(2ll,n,mod);
    res--;
    res+=mod;
    res%=mod;

    ll no1=1;
    ll i,j;
    for(i=n;i>(n-a);i--)
    {
        no1*=i;
        no1%=mod;
    }   
    for(i=1;i<=a;i++)
    {
        no1*=modInverse(i,mod);
        no1%=mod;
    }
    res-=no1;
    res+=mod;
    res%=mod;
    no1=1;
     for(i=n;i>(n-b);i--)
    {
        no1*=i;
        no1%=mod;
    }   
    for(i=1;i<=b;i++)
    {
        no1*=modInverse(i,mod);
        no1%=mod;
    }
    res-=no1;
    res+=mod;
    res%=mod;
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