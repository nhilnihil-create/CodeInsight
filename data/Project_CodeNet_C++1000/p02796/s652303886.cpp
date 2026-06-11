#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  int n; cin >> n;
  vector<pair<ll, ll>> p(n);
  //multi_set<int> l, r;
  rep(i, n){
    cin >> p[i].second >> p[i].first;
    p[i].first += p[i].second;
    //l.insert(x[i] - a[i]);
    //r.insert(x[i] + a[i]);
  }
  sort(p.begin(), p.end());

  int ans = 0;
  ll right = -1e18;

  for(int i = 0; i < n; i++){
    ll left = p[i].second * 2 - p[i].first;
    if(right <= left){
      ans++;
      right = p[i].first;
    }
  }


  cout << ans << endl;


  return 0;
}
