#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int n;
  cin >> n;
  map<string, int> mp;
  vector<string> v;
  string s[n];
  int m = 0;
  rep(i, n){
    cin >> s[i];
    mp[s[i]]++;
    m = max(m, mp[s[i]]);
  }
  rep(i, n){
    if(mp[s[i]] == m) {
      v.push_back(s[i]);
      mp[s[i]] = 0;
    }
  }
  sort(v.begin(), v.end());
  rep(i, v.size()){
    cout << v[i] << endl;
  }

  return 0;
}