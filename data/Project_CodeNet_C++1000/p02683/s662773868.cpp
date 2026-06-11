#include <bits/stdc++.h>
using namespace std;
const int PMAX = 20000000;
int main(){
  int N,M,X,i,j,k;
  cin >> N >> M >> X;
  vector<int> c(N);
  vector<int> s(M);
  vector<vector<int>> A(N,vector<int>(M));
  for(i=0;i<N;i++){
    cin >> c[i];
    for(j=0;j<M;j++)
      cin >> A[i][j];
  }
  int N2 = 1;
  N2 <<= N;
  int scm = PMAX;
  for(i=0;i<N2;i++){
    int sc = 0;
    for(k=0;k<M;k++)
      s[k] = 0;
    for(j=0;j<N;j++){
      if (i & (1 << j)){
        sc += c[j];
        for(k=0;k<M;k++)
          s[k] += A[j][k];
      }
    }
    bool xf = true;
    for(k=0;k<M;k++)
      if (s[k] < X){
        xf = false;
        break;
      }
    if (xf)
      scm = min(scm,sc);
  }
  if (scm != PMAX)
	  cout << scm << "\n";
  else
	  cout << "-1\n";
    

  return 0;
}