#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define mp make_pair
#define pb(x) push_back(x)
#define vll vector<long long>
#define pll pair<long long, long long>
#define mll map<long long, long long>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define gcd __gcd
#define clr(x) memset(x, 0, sizeof(x))
#define mod 1000000007LL
#define mod2 998244353LL
#define INF 1e18
 

typedef long long ll;
typedef long double ld;
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

void solve()
{
    string s;
    cin>>s;
    // no of multiples of 2019 substrings
    mll m;
    m[0]=1;
    ll p10=0;
    ll n=s.length();
    ll i;
    ll res=0;
    const int mm = 2019;
    ll sum=0;
    
    for(i=n-1;i>=0;i--)
    {
       ll no = s[i]-'0';
       ll no2 = no*power(10,p10,mm);
       no2%=mm;
       sum+=no2;
       sum%=mm;
       res+=m[sum];
    //    cout<<sum<<" "<<m[sum]<<"\n";
       m[sum]++;
       p10++;
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