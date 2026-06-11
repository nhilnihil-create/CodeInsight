#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  ll a,b;
  cin >> a >> b;
  
  if(a < b){
    int tmp = a;
    a = b;
    b = tmp;
  }
  
  ll ans = 0;
  for(ll i = 1; ; i++){
    ans = a * i;
    for(ll j = 1; b*j <= ans; j++){
      if(b * j == ans){
        cout << ans << endl;
        return 0;
      }
    }
  }
  
}