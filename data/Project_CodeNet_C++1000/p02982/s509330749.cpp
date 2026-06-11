#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  int N,D,ans=0;cin>>N>>D;
  int X[N][D];
  rep(i,N)rep(j,D) cin>>X[i][j];
  
  for(int i=0;i<N;i++){
	for(int j=i+1;j<N;j++){
      int d2=0;
      rep(k,D) d2+=(X[i][k]-X[j][k])*(X[i][k]-X[j][k]);
      int d=sqrt(d2);
      if(d*d==d2) ans++;
    }
  }
  
  cout << ans << endl;
}
