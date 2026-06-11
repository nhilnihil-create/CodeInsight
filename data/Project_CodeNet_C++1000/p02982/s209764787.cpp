#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,d;cin>>n>>d;
  vector<vector<int>> x(n,vector<int>(d));
  rep(i,n)rep(j,d)cin>>x[i][j];
  int ans=0;
  rep(i,n)for(int j=i+1;j<n;j++){
    int cnt=0;
    rep(k,d){
      int a=x[i][k]-x[j][k];
      cnt+=a*a;
    }
    for(int k=1;k<=cnt;k++){
      if(k*k==cnt)ans++;
    }
  }
  cout<<ans<<endl;
}