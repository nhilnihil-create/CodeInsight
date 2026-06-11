#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll , ll> Pair ;
const int N = 2e5 + 10 ;
ll a[N] , d[N] , sum[N] , zero[N];
int main()
{
  ll k , q ;
  scanf("%lld%lld" , &k , &q) ;
  for(int i = 0; i < k ;i ++)
   scanf("%lld" , &d[i]) ;
  while(q --)
  {
    ll n , x , m ;
    scanf("%lld%lld%lld" , &n , &x , &m) ;
    x %= m ;
    ll sum0 = 0 , sum1 = 0 ;
    sum[0] = 0 , zero[0] = 0 ;
    for(int i = 0 ;i < k ;i ++)
     {
       a[i] = d[i] % m , sum[i + 1] = sum[i] + a[i];
       zero[i + 1] = zero[i] + (a[i] == 0) ;
     }
    int zero0 =  (n - 1) / k * zero[k]  + zero[(n - 1) % k] ;
    sum0 = (x +  (n - 1) / k * sum[k] + sum[(n - 1) % k]) / m - x / m ;
    ll ans = n - 1 - sum0 - zero0 ;
    cout << ans << endl ;
  }
  return 0 ;
}
