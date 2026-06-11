#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  vector<ll> now(3, 0);
  ll res = 3;
  bool ok = 1;
  for (int i = 0; i < n; i++){
    ll a;
    cin >> a;
    
    if (i != 0){
      if (a == now[0] && now[0] == now[1] && now[1] == now[2]){
        res *= 3;
        res %= MOD;
        now[2]++;
      }
      else if (a == now[0] && now[0] == now[1]){
        res *= 2;
        res %= MOD;
        now[1]++;
      }
      else if (a == now[0]){
        now[0]++;
      }
      else if (a == now[1] && now[1] == now[2]){
        res *= 2;
        res %= MOD;
        now[2]++;
      }
      else if (a == now[1]){
        now[1]++;
      }
      else if (a == now[2]){
        now[2]++;
      }
      else
        ok = 0;
    }
    else {
      if (a == 0)
        now[2]++;
      else
        ok = 0;
    }
  }

  if (ok)
    cout << res << endl;
  else
    cout << 0 << endl;

  return 0;
}
