#include <bits/stdc++.h>
#define ll long long int
#define db double
#define pb push_back
#define mpr make_pair
#define andl "\n"
#define f first
#define s second
#define mset(x,y) memset(x,y,sizeof(x))
#define fr(i,n) for(long long int i=0;i<n;i++)
#define trace(it,x) for(auto it = (x).begin(); it != (x).end(); it++)
#define mod 1000000007
#define fastio ios::sync_with_stdio (false); cin.tie (0); cout.tie (0);
#define runtime cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
using namespace std;
 
// convert number to string to_string(x);
// convert string to number stoi();
 
// ll mulmod(ll x,ll y)
// {
//     return ((x%mod)*(y%mod))%mod;
// }
 
// ll binpow(ll x, ll y)
// {
//     ll z = 1;
//     while(y > 0)
//     {
//         if(y % 2 == 1)
//             z = mulmod(z, x);
//         x = mulmod(x, x);
//         y /= 2;
//     }
//     return z;
// }
 
// ll ncr(ll n,ll r)
// {
//     return mulmod(fact[n],binpow(mulmod(fact[n-r],fact[r]),mod-2));
// }
 
// ll pwr(ll n,ll m)
// {
//   if(n==1 || m==0)
//     return 1;
 
//   ll x=pwr(n,m/2);
//   if(m%2==0)
//     return x*x;
//   else
//     return n*x*x;
// }
 
// ll pwr(ll n,ll m,ll b)
// {
//   if(n==1 || m==0)
//     return 1;
 
//   ll x=pwr(n,m/2,b);
//   if(m%2==0)
//     return ((x%b)*(x%b))%b;
//   else
//     return ((n%b)*(((x%b)*(x%b))%b))%b;
// }
 
void solve()
{
  return ;
}
 
int main()
{
  fastio
  
  string s;
  cin >> s;

  ll n=s.length();
  if(s[n-1]!='s' || s[n-1]=='e')
    cout << s+"s";
    else

        cout << s+"es";
 
  runtime
}