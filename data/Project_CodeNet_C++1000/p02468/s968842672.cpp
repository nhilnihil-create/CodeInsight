#include <bits/stdc++.h>
#define ll long long

using namespace std;
#define MOD 1000000007
int main(){
  ll m, n;
  cin >> m >> n;
  ll ans = 1;
  ll i = m;
  while(n){
    if(n & 1 == 1){
      ans = ans * i % MOD;
    }
    i = i * i % MOD;
    n >>= 1;
  }
  cout << ans << endl;
  
}