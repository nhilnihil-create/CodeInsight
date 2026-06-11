#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll n, k;
  cin >> n >> k;
  
  vector<ll> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
  }
  sort(p.begin(), p.end());
  
  ll ans = 0;
  for (int i = 0; i < k; i++){
    ans += p[i];
  }
  cout << ans << endl;

  return 0;
}
