#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll gcd(ll a,ll b)
{
   if(a%b==0)
   {
       return(b);
   }
   else
   {
       return(gcd(b,a%b));
   }
}

ll lcm(ll a,ll b)
{
   return a/gcd(a,b)*b;
}

int main()
{
  ll A,B; cin>>A>>B;
  cout<<lcm(A,B)<<endl;
  return 0;
}
