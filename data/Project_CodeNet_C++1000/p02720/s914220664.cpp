#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<ll> ans;

void dfs(int d, ll now){
  ans.push_back(now);

  if(d==10) return;

  for(int j = -1; j<=1; j++){
    int add = (now % 10) + j;
    if(add>=0 && add <= 9) dfs(d+1, now*10+add);
  }
}
int main(){
  for(int i=1; i<=9; i++){
    dfs(1,(ll)i);
  }
  sort(ans.begin(),ans.end());
  int k; cin>>k;
  cout<<ans[k-1]<<endl;
}
