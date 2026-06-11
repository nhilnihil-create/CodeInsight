#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;

int main() {
  ll n;
  cin >> n; 
  string s;
	map<string,ll> m;
  rep(i,n){
    cin >> s;
    sort(s.begin(),s.end());
    m[s]++;
  }
  ll ans =0;
  auto begin = m.begin(), end = m.end();
  for(auto iter = begin;iter != end; iter++){
    //cout << iter->first << " " << iter->second << endl;;
    ll t = iter->second;
    ans += t * (t - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}