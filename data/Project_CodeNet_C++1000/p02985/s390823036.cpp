#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

void dfs2(vector<vector<int>> &ab, vector<vector<int>> &ab2, int parent, int now){
  for(int i=0; i<ab.at(now).size(); i++){
    if(ab.at(now).at(i)==parent) continue;
    ab2.at(now).push_back(ab.at(now).at(i));
    dfs2(ab,ab2,now,ab.at(now).at(i));
  }
}

ll dfs(vector<vector<int>> &ab, int now, int ban, ll &ans, int k, int depth){
  int l = min(depth,2);
  ans *= max(k-l-ban, 0);
  ans %= MOD;
  int m = ab.at(now).size();
  for(int i=0; i<m; i++){
    dfs(ab, ab.at(now).at(i), i, ans,k,depth+1);
  }
  return ans;
}

int main(){
  
  int n,k; cin>>n>>k;
  vector<vector<int>> ab(n);
  for(int i=0; i<n-1; i++){
    int a,b; cin>>a>>b;
    --a; --b;
    ab.at(a).push_back(b);
    ab.at(b).push_back(a);
  }
  vector<vector<int>> ab2(n);
  dfs2(ab,ab2,-1,0);
  ll ans{1};
  dfs(ab2,0,0,ans,k,0);
  cout << ans << endl;
  
  
}
