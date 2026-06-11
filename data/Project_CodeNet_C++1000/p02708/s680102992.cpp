#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main(){
  ll n, k;
  ll minnum, maxnum;
  cin >> n >> k;
  ll ans = 0;
  for(ll i=k; i<=n+1; ++i){
    minnum = i * (i-1) /2;
    maxnum = (n+(n-i+1)) * i /2;
    ans += maxnum - minnum +1;
    ans %= MOD;
  }
  cout << ans << endl;
}