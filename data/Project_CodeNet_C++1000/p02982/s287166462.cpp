#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

bool is_integer(double x){
  double r;
  return 0==std::modf(x,&r);
}

int main() {
  int N,D,ans=0;
  cin>>N>>D;
  vector<vector<int>> X(N,vector<int>(D));
  rep(i,N)rep(j,D)cin>>X[i][j];
  rep(i,N)for(int j=i+1;j<N;j++){
      double L=0;
      rep(k,D){
        double p=pow(X[i][k]-X[j][k],2);
        L+=p;
      }
      double q=pow(L,0.5);
      if(is_integer(q))ans++;
  }
  cout << ans<<endl;
  return 0;
}