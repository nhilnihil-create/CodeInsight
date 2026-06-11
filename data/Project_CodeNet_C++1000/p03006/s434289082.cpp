#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  set<pair<ll, ll>> s;
  for (int i = 0; i < n; i++){
    ll x, y;
    cin >> x >> y;
    
    s.insert(make_pair(x, y));
  }

  ll ans = INF;
  for (auto i : s){
    for (auto j : s){
      if (i == j)
        continue;

      ll num = 0;
      ll p = i.first - j.first;
      ll q = i.second - j.second;
      for (auto k : s){
        if (s.find(make_pair(k.first - p, k.second - q)) != s.end())
          num++;
      }

      ans = min(ans, n - num);
    }
  }
  
  cout << (ans == INF ? 1 : ans) << endl;

  return 0;
}
