#include <bits/stdc++.h>
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
#define INF 1000000000007
 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;


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
     ll n,k;
     cin>>n>>k;
     ll i,j;
     ll cnt[k+1];
     clr(cnt);
     for(i=1;i<=k;i++)
     {
        cnt[i]=k/i;
     }
     ll ans[k+1];
     clr(ans);
     for(i=k;i>=1;i--)
     {
        ll tans=power(cnt[i],n,mod);
        for(j=2*i;j<=k;j+=i)
        {
            tans-=ans[j];
            tans%=mod;
            tans+=mod;
            tans%=mod;
        }
        ans[i]=tans;
     }
    ll nos2=0;
    ll res=0;
    for(i=1;i<=k;i++)
    {
      ll tans=ans[i]*i;
      res+=tans;
      res%=mod;      
    }
    res%=mod;
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