#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<vector>
#include<utility>
#include<cstring>
#define pb(a)             push_back(a)
#define mp(a,b)           make_pair(a,b)
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define loop(i,a)          for(int i=1;i<=a;i++)
#define pii                pair <int,int>
#define sl(a)              scanf("%I64d",&a)
#define sll(a,b)           scanf("%I64d %I64d",&a,&b)
#define si(a)              scanf("%d",&a)
#define sii(a,b)           scanf("%d %d",&a,&b)
using namespace std ;
typedef long long ll ;
const ll mod = 1e9+7;
ll fastpow(ll n,ll k,ll p)//log k
{
    ll ans = 1 ;
    //n = n%p ;
   // if(n==0){return 0 ;}
    while(k>0)
    {
        if(k&1)
        {
            ans = (ans*n)%p;
        }
        k = k >> 1 ;
        n = (n*n)%p;
    }
    return ans ;
}
int main()
{
  //cout << fastpow(5,6,mod) << endl;
  ll n,k;
  cin >> n >> k ;
  ll gcd[k+5],sum=0;
  for(ll i=1;i<=k;i++)
  {
      ll a = k/i ;
      ll p =  fastpow(a,n,mod)%mod;
      gcd[i] = p;
  }
  for(int i=k;i>0;i--)
  {
      for(int j=i+i;j<=k;j+=i)
      {
          gcd[i]-=gcd[j];
      }
  }
  ll ans = 0 ;
  loop(i,k)
  {
      ll x = (gcd[i]*i)%mod;
      ans = (ans+x)%mod;
  }
  cout << ans << endl;
  return 0 ;
}
