#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){

  ll s;
  cin >> s;
  ll mx = 1000000000;
  ll k = (mx-s%mx)%mx;
  ll l = (s+k)/mx;
  printf("0 0 1000000000 1 %lld %lld\n",k,l);
  




  return 0;
}