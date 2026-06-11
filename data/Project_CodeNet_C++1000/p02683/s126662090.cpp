#include<iostream>
#include<vector>
using namespace std;

int main() {
  int N,M,X,i,j,k;
  cin>>N>>M>>X;
  vector<int> C(N);
  vector<vector<int> > A(N, vector<int>(M));
  for (i=0;i<N;i++) {
      cin>>C[i];
    for (j=0;j<M;j++) {
      cin>>A[i][j];
    }
  }
  int ans=12e5+1,SC;
  vector<int> SA;
  for (i=0;i<(1<<N);i++) {
    SC=0;
    SA=vector<int>(M,0);
    for (j=0;j<N;j++) {
      if (i & (1<<j)) {
        SC+=C[j];
        for (k=0;k<M;k++) SA[k]+=A[j][k];
      }
    }
    for (k=0;k<M && SA[k]>=X;k++){}
    if (k==M) ans=min(ans, SC);
  }
  cout<<(ans < 12e5+1 ? ans : -1)<<endl;
  return 0;
}
