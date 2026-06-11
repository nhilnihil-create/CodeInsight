#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

vector<vector<P>> ver;
vector<int> ans;
int ansnum = 0;

void dfs(int x, int ng){
  int col = 1;
  for(auto p: ver[x]){
    if(ans[p.second] != 0) continue;
    if(col == ng) ++col;
    ans[p.second] = col;
    ansnum = max(ansnum, col);
    dfs(p.first, col);
    ++col;
  }
}

int main(){
  int n, a, b;
  cin >> n;
  ver.resize(n);
  ans.resize(n);
  for(int i=0; i<n-1; ++i){
    cin >> a >> b;
    --a; --b;
    ver[a].push_back(make_pair(b,i));
    ver[b].push_back(make_pair(a,i));
  }
  dfs(0, -1);
  cout << ansnum << endl;
  for(int i=0; i<n-1; ++i){
    printf("%d\n",ans[i]);
  }
}