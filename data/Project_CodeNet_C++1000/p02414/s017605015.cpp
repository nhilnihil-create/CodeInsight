#include<iostream>
using namespace std;

int main(){
  int n,m,l;
  cin >> n >> m >> l;
  long long t;
  long long A[n][m],B[m][l];

  //?????????+??\???
  for(int i = 0; i<n; i++){
    for(int k = 0; k<m; k++){
      A[i][k] = 0;
      cin >> A[i][k];
    }
  }
  for(int k = 0; k<m; k++){
    for(int j = 0; j<l; j++){
      B[k][j] = 0;
      cin >> B[k][j];
    }
  }

  //?????????
  for(int i=0; i<n; i++){
    for(int j=0; j<l; j++){

      if(j!=l-1){
        for(int k=0; k<m; k++){
          t += A[i][k] * B[k][j];
          if(k == m-1){
            cout << t << " ";
            t = 0;
          }
        }
      }

      else{
        for(int k=0; k<m; k++){
          t += A[i][k] * B[k][j];
          if(k == m-1){
            cout << t << endl;
            t = 0;
          }
        }
      }
    }
  }

  return 0;
}