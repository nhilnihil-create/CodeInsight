#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  ll m;
  cin >> m;
  
  vector<ll> d(m), c(m);
  ll sum = 0, k = 0;
  for (int i = 0; i < m; i++){
    cin >> d[i] >> c[i];
    sum += d[i] * c[i];
    k += c[i];
  }

  cout << k - 1 + (sum - 1) / 9 << endl;

  return 0;
}
