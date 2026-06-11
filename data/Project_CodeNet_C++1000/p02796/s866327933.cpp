#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1000000000000000000
#define P pair<ll,ll>

using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  vector<ll> x(n), l(n);
  for (int i = 0; i < n; i++){
    cin >> x[i] >> l[i];
  }
  vector<P> p(n);
  for (int i = 0; i < n; i++){
    p[i] = P(x[i]+l[i],x[i]-l[i]);
  }
  sort(p.begin(), p.end());
  
  ll ima = -INF;
  ll ans = 0;
  for (int i = 0; i < n; i++){
    if (ima <= p[i].second){
      ans++;
      ima = p[i].first;
    }
  }
  cout << ans << endl;
  

  return 0;
}
