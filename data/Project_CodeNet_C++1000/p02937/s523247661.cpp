#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}



int main() {
  string s,t;
  cin >> s >> t;
  set<char> cnt;
  map<char,vector<int>> mp;
  ll res=0,now=-1;
  rep(i,s.size()){
    cnt.insert(s[i]);
    mp[s[i]].push_back(i);
  }
  rep(i,t.size()){
    if (cnt.find(t[i])==cnt.end()) {
      cout << -1 << endl;
      return 0;
    }
  }

  rep(i,t.size()){
    char tmp = t[i];
    auto ix = upper_bound(mp[tmp].begin(),mp[tmp].end(),now);
    if (ix==mp[tmp].end()) {
      res++;
      now=mp[tmp][0];
    }
    else {
      now=*ix;
    }
  }
  cout << res*s.size() + now + 1 << endl;
}