#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
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
mint exp(int a,int n)
{
  mint t=a;
  mint ans;
  ans=(n%2==0)? 1:t;
  n>>=1;
  while(n>0)
  {
    t=t*t;
    if(n%2==1)ans=(ans.x==1)?t:ans*t;
    n>>=1;
  }
  return ans;
}
int main()
{
  int n,a,b;
  cin>>n>>a>>b;
  
  mint ans=exp(2,n)-1;
  //cout<<ans.x<<endl;
  mint A;
  mint B;
  mint d=1;
  mint fa=1;
  mint fb=1;
  for(int i=0;i<max(a,b);i++)
  {
    if(i<a)fa*=(i+1);
    if(i<b)fb*=(i+1);
    
    d*=(n-i);
    //cout<<d.x<<endl;
    if(i==a-1)A=d;
    if(i==b-1)B=d;
  }
  //cout<<A.x<<" "<<B.x<<endl;
  A*=exp(fa.x,mod-2);
  B*=exp(fb.x,mod-2);
  ans-=(A+B);
  
  cout<<ans.x<<endl;
    
  return 0;
}