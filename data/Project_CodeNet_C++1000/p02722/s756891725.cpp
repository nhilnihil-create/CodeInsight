#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  ll n;
  cin >> n;
  ll res = 1;
  for(ll i = 2;i*i <= n;i++){
    if((n%i))continue;
    ll k = i;
    ll m = n;
    while(!(m%k))m /= k;
    if((m%k) == 1)res++;
    k = n/i;
    m = n;
    while(!(m%k))m /= k;
    if((m%k) == 1 && i*i != n)res++;
  }
  n--;
  for(ll i = 2;i*i <= n;i++){
    if((n%i))continue;
    res += 2;
    if(i*i == n)res--;
  }
  if(n != 1)res++;
  cout << res << endl;


  return 0;
}