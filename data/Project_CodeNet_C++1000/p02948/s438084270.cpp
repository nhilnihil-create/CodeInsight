#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll mod = 1e9 + 7;
const ll MAXN = 1e5 + 5;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n, m;
  cin >> n >> m;
  vector < pair < ll, ll > > v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i].second >> v[i].first;
    v[i].first = -v[i].first;
  }

  sort(v.begin(), v.end());

  multiset < ll > s;
  for(int i = 0; i <= m; i++) s.insert(i);

  ll ans = 0;
  for(auto i : v){
    auto it = s.lower_bound(i.second);
    if(it != s.end()){
      ans -= i.first;
      s.erase(it);
    }
  }

  cout << ans << '\n';
}
