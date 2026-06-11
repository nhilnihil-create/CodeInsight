#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  vector<ll> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  
  if (n % 3 != 0){
    int ok = 1;
    for (int i = 0; i < n; i++){
      if (a[i] != 0)
        ok = 0;
    }
    if (ok)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  else {
    ll t = 0;
    for (int i = 0; i < n; i++){
      t ^= a[i];
    }
    if (t == 0)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}
