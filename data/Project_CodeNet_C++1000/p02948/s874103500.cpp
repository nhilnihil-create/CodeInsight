#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> job(m+1);
  rep(i,n){
    int a,b;
    cin>>a>>b;
    if(a<=m) job[a].pb(b);
  }  
  int ans = 0;
  priority_queue<int> q;
  rep(i,m+1){
    for(auto x:job[i]){
      q.push(x);
    }
    if(!q.empty()){
      ans += q.top();
      q.pop();
    }
  }
  cout << ans << endl;
}