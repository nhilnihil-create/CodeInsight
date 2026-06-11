#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  ll n, k;
  cin >> n >> k;
  
  vector<ll> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  vector<ll> b(n, 0), c(n, 0);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (a[i] > a[j])
        b[i]++;
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = i; j < n; j++){
      if (a[i] > a[j])
        c[i]++;
    }
  }
  ll ans = 0;
  for (int i = 0; i < n; i++){
    ans = (ans + c[i] * k % MOD + b[i] * (k * (k - 1) / 2 % MOD) % MOD) % MOD;
  }
  cout << ans << endl;
  
  

  

  return 0;
}
