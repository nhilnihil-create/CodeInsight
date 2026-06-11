#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i,n){
    string t;
    cin >> t;
    sort(t.begin(),t.end());
    s[i] = t;
  }
  map<string, ll> mp;
  rep(i,n) mp[s[i]] ++;
  ll ans = 0;
  for(auto p : mp){
    ans += p.second*(p.second-1)/2;
  }
  cout << ans << endl;
}
