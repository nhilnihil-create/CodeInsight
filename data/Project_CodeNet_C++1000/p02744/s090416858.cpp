#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
  #include "_DEBUG.hpp"
#endif
#define int long long
const int INF = 1LL << 60;

signed main(){

  int n; cin >> n;
  vector<string> v;
  auto dfs = [&](auto&& dfs, int i, string s)->void{
    if(i == n){
      v.push_back(s);
      return;
    }
    char Max = 'a';
    for(int i = 0; i < s.size(); i++){
      Max = max(Max, s[i]);
    }
    for(char c = 'a'; c <= Max+1; c++){
      dfs(dfs, i+1, s+c);
    }
  };
  dfs(dfs, 1, "a");
  sort(v.begin(), v.end());
  for(auto t : v){
    cout << t << endl;
  }

  return 0;
}