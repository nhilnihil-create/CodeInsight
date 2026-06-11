#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000
#define N 1000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  vector<ll> a(n);
  vector<ll> check(N + 1, 0); // 0 : 関係なし, 1 : セーフかも, 2 : アウト
  vector<ll> num(N + 1, 0);
  for (int i = 0; i < n; i++){
    cin >> a[i];

    num[a[i]]++;
  }

  if (num[0] == 1){
    cout << 1 << endl;
  }
  else if (num[2] >= 2){
    cout << 0 << endl;
  }
  else {
    for (ll i = 0; i < n; i++){
      if (check[a[i]] == 0){
        check[a[i]] = 1;
        for (ll j = a[i]*2; j <= N; j += a[i]){
          check[j] = 2;
        }
      }
      else if (check[a[i]] == 1)
        check[a[i]] = 2;
    }
    ll ans = 0;
    for (ll i = 0; i <= N; i++){
      ans += (check[i] == 1 ? 1 : 0);
    }
    cout << ans << endl;
  }
 

  return 0;
}
