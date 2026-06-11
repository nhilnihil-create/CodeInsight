#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;


ll ll_pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % 2019;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x = x * x % 2019;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

int main() {
  string S;
  cin>>S;
  ll N=S.size();
  vector<ll> amari(N);
  reverse(S.begin(),S.end());
  rep(i,N)
  {
    ll a=S.at(i)-'0';
    /*rep(j,i)
    {
      a*=10;
      a%=2019;
    }*/
    
    a=a*ll_pow(10,i)%2019;
    amari.at(i)=a;
  }
  vector<ll> sum(N);
  rep(i,N)
  {
    if(i==0)
    {
      sum.at(0)=amari.at(0);
    }
    else
    {
      ll a=sum.at(i-1)+amari.at(i);
      sum.at(i)=a%2019;
    }
  }
  ll ans=0;
  vector<ll> num(2019);
  rep(i,N)
  {
    ll a=sum.at(i);
    num.at(a)++;
  }  
  rep(i,2019)
  {
    ll a=0;
    if(i==0)
    {
      ll b=num.at(0);
      if(b==0)
      {
        a=0;
      }
      else
      {
        a=b+b*(b-1)/2;
      }
    }
    else
    {
      ll b=num.at(i);
      if(b<=1)
      {
        a=0;
      }
      else
      {
        a=b*(b-1)/2;
      }
    }
    ans+=a;
  }
  cout<<ans<<endl;
  return 0;
}
