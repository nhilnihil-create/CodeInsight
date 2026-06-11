#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000
int MOD=1000000007;
vector<int>tas(200001);
vector<int>visited(200001);
vector<vector<int>>chi(200001,vector<int>(0));
void dfs(int k){
  visited[k]=1;
  rep(i,chi[k].size()){
    if(!visited[chi[k][i]]){tas[chi[k][i]]+=tas[k];
    dfs(chi[k][i]);
  }
  }
}
signed main() {
  int n, q;
  cin>>n>>q;
  vector<int>par(n);
rep(i,n-1){
  int t1,t2;
  cin>>t1>>t2;
    chi[t2-1].push_back(t1-1);
    chi[t1-1].push_back(t2-1);
}
rep(i,q){
  int num,tmp;
  cin>>num>>tmp;
  tas[num-1]+=tmp;
}

dfs(0);
rep(i,n){
  cout<<tas[i]<<endl;
}
}
