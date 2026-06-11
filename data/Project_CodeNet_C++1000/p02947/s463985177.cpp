#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);


int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  map<string, int> mp;

  REP(i,n){
    string x;
    cin >> x;
    sort(ALL(x));
    s[i] = x;
  }

  REP(i,n){
    ++mp[s[i]];
  }

  ll ans = 0;
  for(auto& p : mp){
    int s = p.second;
    ans += (ll)s*(s-1)/2;
  }
  cout << ans << endl;

  return 0;
}