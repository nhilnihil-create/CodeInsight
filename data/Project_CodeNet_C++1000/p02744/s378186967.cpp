#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

void dfs(string s, int n, int type){
  if(s.size() == n){
    cout << s << endl;
    return ;
  }
  rep(i, type + 2){
    string add = s;
    add.push_back(i + 'a');
    dfs(add, n, max(type, i));
  }
}

int main(){
  int n;
  cin >> n;
  dfs("a", n, 0);
  return 0;
}