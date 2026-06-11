#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=10000000000000000;
signed main(){
  int N,M;
  cin>>N>>M;
  vector<vector<int>> A(M+1,vector<int>(1<<N,INF));
  A[0][0]=0;
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    int bit=0;
    while(b--){
      int c;
      cin>>c;
      bit=bit|(1<<(c-1));
    }
    for(int j=0;j<(1<<N);j++)A[i+1][j]=A[i][j];
    for(int j=0;j<(1<<N);j++)A[i+1][j|bit]=min(A[i+1][j|bit],A[i][j]+a);
  }
  cout<<(A[M][(1<<N)-1]==INF?-1:A[M][(1<<N)-1])<<endl;
}