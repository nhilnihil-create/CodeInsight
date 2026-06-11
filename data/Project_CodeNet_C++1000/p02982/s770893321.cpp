#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
 
int main(){
  int N,D;
  cin>>N>>D;
  vector<vector<int>> d(N,vector<int>(D));
  rep(i,N){
    rep(j,D) cin>>d[i][j];
  }
  int ans=0;
  double ja=0;
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      ja=0;
      for(int k=0;k<D;k++){
        ja+=(d[i][k]-d[j][k])*(d[i][k]-d[j][k]);
      }
      ja=sqrt(ja);
      for(int k=1;k<=126;k++){
        if(ja==k){
          ans++;
        }
      }
    }
  }
  cout<<ans<<endl;
}