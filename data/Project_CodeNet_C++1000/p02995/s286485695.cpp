#include <bits/stdc++.h>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)




using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const ll Lmax=ll(1e18);
const ll Nmax=1e9;
const ll INF=1e9;

ll gcd(ll a, ll b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}
ll lcm(ll a, ll b)
{
   return a * b / gcd(a, b);
}

int main(){
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  ll n_ac,n_ad,n_acd;
  ll n_bc,n_bd,n_bcd;



  n_ac=(a-1)/c;//aより小さい数で，cで割り切れる数
  n_bc=b/c;

  n_ad=0; n_acd=0;
  n_bd=0; n_bcd=0;

  if(c!=d){
    n_ad=(a-1)/d;
    n_acd=(a-1)/(lcm(c,d));

    n_bd=b/d;
    n_bcd=b/(lcm(c,d));
  }
  ll ans=(b-n_bc-n_bd+n_bcd)-(a-1-n_ac-n_ad+n_acd);
  cout<<ans<<endl;



}
