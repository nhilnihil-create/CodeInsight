#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<ll>>;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define MOD 1000000007
#define INF 1000000
#define PI 3.14159265358979323846264338327950L
#define MAX_N 200010
#define lb lower_bound //[2,4)=lb(4)-lb(2);

ll countPrimes(ll n)
{
  ll count=0;
  if (n%2==0) 
  {
    count++;
    while (n%2==0) n/=2;
  }
  for (ll i=3;i*i<=n;i=i+2)
  {
    while (n%i==0) 
    {
      n /= i;
      if (n%i!=0) count++;
    }
  }
  if (n != 1) count++;
  return (count);
}
  
int main()
{
  ll a,b;
  cin>>a>>b;
  ll g = __gcd(a,b);
  
  cout<<countPrimes(g)+1<<endl;
}