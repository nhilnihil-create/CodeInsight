#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using Graph = vector<vector<ll>>;
using P = pair<int,int>;
#define MOD 1000000007
#define INF 1000000

/*
受験の時にやった重複順列とか言うやつ
矢印を入れ替える問題

X-Kがマイナスになる場合を考慮してなかった・・・・・

*/

ll X,Y,K;

ll fac[1000100];

void fac_init()
{
  fac[0]=1;
  fac[1]=1;
  for (int i=2;i<=1000100;i++)
  {
     fac[i] = fac[i-1]*i % MOD;
  }
}

ll fast(ll a,ll n)
{
  ll ans = 1;
  while (n>0)
  {
    if (n & 1)
      ans *= a; 
    ans %= MOD;
    a *= a;
    a %= MOD;
    n /= 2;
  }
  return (ans);
}

int main()
{
  cin>>X>>Y;
  if ((X+Y) % 3 != 0)
  {
    cout<<0<<endl;
    return (0);
  }
  
  K = (X+Y)/3;
  ll n = X-K;
  ll m = K-n;
  
  if (n<0 || m<0)
  {
    cout<<0<<endl;
    return (0);
  }
  //cout<<K<<" "<<n<<" "<<m<<endl;
  
  fac_init();
  
  //for (int i=2;i<=10;i++)
    //cout<<"fac["<<i<<"]="<<fac[i]<<endl;
  
  ll top = fac[n+m] % MOD;
  ll bot = fac[n]*fac[m] % MOD;
  
  ll ans = top * fast(bot, MOD-2) % MOD;
  cout<<ans<<endl;
}