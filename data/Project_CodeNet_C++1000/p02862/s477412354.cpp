#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
struct mint {
  ll x;
  mint(ll x=0):x(x%mod){}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
};
mint modp(int a,int p)
{
  mint x=a;
  mint y=(p%2==0)?1:a;
  p/=2;
  while(p!=0)
  {
    x=x*x;
    if(p%2==1)
    {
      y=(y.x==1)? x : x*y;
    }   
     p/=2;
  }
   return y;
}
int main()
{
  int x,y;
  cin>>x>>y;
  if((x+y)%3!=0)
  {
    cout<<0<<endl;
    return 0;
  }
  int m=((2*x)-y)/3;
  int n=((2*y)-x)/3;
  if(m<0 || n<0)
  {
    cout<<0<<endl;
    return 0;
  }
  
  int g=n+m;
  mint d=1;
  int a=(n+m-max(m,n));
  
  mint u=1;
  while(g>(n+m-a))
  {
    u*=g;
    g--;
  }
  for(int i=1;i<=a;i++)d*=i;
  
 
  d=modp(d.x,mod-2);
  mint ans=d*u;
  cout<<ans.x<<endl;
 	return 0;
}