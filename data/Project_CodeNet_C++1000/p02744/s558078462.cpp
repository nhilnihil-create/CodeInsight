//答え見ました。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 1000000007;

int n;

void dfs(string s,char mx){
  if(s.size()==n) printf("%s\n", s.c_str());
  else{
    for(char c='a'; c<=mx; c++){
      if(c==mx) dfs(s+c,mx+1);
      else dfs(s+c,mx);
    }
  }
}


int main() {
  cin >> n;
  dfs("",'a');
  return 0;
}