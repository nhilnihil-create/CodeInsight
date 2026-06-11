#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,d;cin>>n>>d;
  int ans=0;
  vector<vector<int>> x(n,vector<int>(d));
  rep(i,n)rep(j,d)cin>>x[i][j];
  rep(i,n-1)for(int j=i+1;j<n;j++){
    int cnt=0;
    rep(k,d){
      cnt+=(x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
    }
    for(int k=1;k<=sqrt(cnt);k++){
      if(k*k==cnt){
        ans++;
        break;
      }
    }
  }
  cout<<ans<<endl;
}