#include<bits/stdc++.h>
//#include <iomanip>
#define hell                         1000000007
#define M                            1000000007
#define Maxi                      10000000000000000
#define lcm(a,b)                     (a*b)/__gcd(a,b)
#define ll                           long long
 
#define vll                          vector<ll>
#define vi                           vector<long long>
#define pll                          vector< pair<ll,ll> >
#define pb                           push_back
//#define mp                           make_pair
#define all(v)                       v.begin(),v.end()
#define lbnd                         lower_bound
#define ubnd                         upper_bound
#define bs                           binary_search
#define F                            first  
#define S                            second
#define rep(i,a,b)                   for(i=a;i<b;i++)
#define parr(a,n)                    for(i=0;i<n;i++) cout<<a[i]<<" ";cout<<endl;
#define pcont(a)                     for(auto i:a) cout<<i<<" ";cout<<endl;
#define ret(x)                       return cout<<x,0;
#define dbg(x)                       cout << #x << " is " << x << endl;
#define endl                           '\n'
 //const ll infl=0x3f3f3f3f3f3f3f3fLL;

 #define pi                           3.141592653589793238
// Debug //
 
#define trace(x)                 cerr << #x << ": " << x << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
using namespace std;

/*ll prime[1000006];
void fun()
{
  for(ll i=2;i<=1000000;i++)
  {
    if(prime[i]==0)
    {
      for(ll j=i;j<=1000000;j+=i)
      {
        if(prime[j]==0)
        prime[j]=i;
      }
    }
  }
}*/
/*const int MAXR = 1000005;

ll cubic_root(ll x)
{
    ll l = 0, r = MAXR;
    while (l != r) {
        ll m = (l + r + 1) / 2;
        if (m * m * m > x)
            r = m - 1;
        else
            l = m;
    }
    return l;
}*/

/*ll power(ll x,ll y,ll m) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
 
    return (y%2 == 0)? p : (x * p) % m; 
}*/
/*bool checkprime(ll n)
{ 
  ll i;
  if(n<=3)
    return true;

  if(n%2==0 || n%3==0)
    return false;

  for(i=5;i*i<=n;i+=6)
  {
    if(n%i==0 || n%(i+2)==0)
      return false;
  }

  return true;

}

 ll check(ll n,ll b) 
{
  ll i,p=1,P=1,ans=1;
  if(n<3)
    return 0;
  for(i=1;i<=b;i++)
  {
    ans=ans*(n-i+1/i)%hell;
  }

  return ans;
}*/

/*const int N = 1e6+1;

ll prime[N];
//ll n;
vector<ll>p;
vector<int>ans;


void sv()
{
  for(int i=1;i<N;i++)
    prime[i]=1;

  for(int i=2;i*i<=N;i++)
  {
    if(prime[i])
    {
      for(int j=i*i;j<N;j+=i)
      {
        prime[j]=0;
      }
    }
  }

  for(int i=2;i<N;i++)
  {
    if(prime[i])
      p.pb(i);
  }
  return ;
}
*/
/*void solve()
{
  int n;
  cin>>n;
  sv();
  for(auto i:p)
  {
    if(i>n)
      break;

    for(int j=1;pow(i,j)<=n;j++)
      ans.pb(pow(i,j));
  }

  cout<<ans.size()<<endl;
  for(auto i:ans)
    cout<<i<<" ";
  cout<<endl;
  //cout<<"ef"<<endl;
return ;
}*/
/*ll m;
long long fast_power(long long base, long long power) {
    long long result = 1;
    while(power > 0) {

        if(power % 2 == 1) { // Can also use (power & 1) to make code even faster
            result = (result*base) % m;
        }
        base = (base * base) % m;
        power = power / 2; // Can also use power >>= 1; to make code even faster
    }
    return result;
}*/


int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);cout.tie(NULL);
      ll n;
      cin>>n;

      ll ans=n*(n-1)/2;
      cout<<ans<<endl;
}