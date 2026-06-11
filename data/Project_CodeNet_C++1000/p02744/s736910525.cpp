#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

void dfs(int n, string now, vector<string> &vec, int d=1){
  if(now.size() == n){
    vec.push_back(now);
    return;
  }
  for(int i = 0; i <= d; i++){
    string next = now+char('a'+i);
    int m=d;
    if(i==d) m++;
    dfs(n,next,vec,m);
  }
}

int main(){
  int n;
  cin>>n;
  vector<string> ans;
  dfs(n,"a",ans);
  for(auto x : ans) cout<<x<<endl;
}
