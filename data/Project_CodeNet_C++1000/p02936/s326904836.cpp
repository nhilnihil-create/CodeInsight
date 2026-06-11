#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <iostream>
#include <ctype.h>
#include <string>
typedef long long ll;
using namespace std;


void dfs(vector <bool>&seen, vector<vector<int>> &pair, vector<int> &sum, vector<int> &ans, int k){
  seen[k]=true;
  for(int i : pair[k]){
    if(seen[i]==true) continue;
    else {
      ans[i]=ans[k] + sum[i];
      dfs(seen, pair, sum, ans, i);
    }
  }
}

int main(){
  int n,m;
  cin>>n>>m;
  vector <vector<int>> pair(n);
  rep(i,n-1) {
    int a,b;
    cin>>a>>b;
    pair[a-1].push_back(b-1);
    pair[b-1].push_back(a-1);
  }
  vector<bool> seen (n,false);

   vector<int> sum(n,0);
  rep(i,m){
    int p,x;
    cin>>p>>x;
    sum[p-1]+=x;
  }
  vector<int> ans(n);
  ans[0]= sum[0];

  dfs(seen, pair, sum, ans, 0);

 
  rep(i,n){
    cout<<ans[i]<<" ";
  }

  

}