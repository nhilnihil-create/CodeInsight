#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;
int main(){
  ll n,k; cin >> n >> k;
  ll ans = 0;
  vector<ll> h(n);

  rep(i,n){
    cin >> h.at(i);
    ans += h.at(i);
  }

  sort(all(h));
  reverse(all(h));

  rep(i,min(k,n)){
    ans -=h.at(i);
  }

  cout << ans << endl;
}
