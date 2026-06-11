#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, d;
  cin >> n >> d;
  
  vector<vector<int>> x(n, vector<int>(d));
  for(int i=0; i<n; i++){
    for(int j=0; j<d; j++){
      cin >> x[i][j];
    }
  }
 
  int num=0; 
  
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      int dissqr = 0;
      for(int k=0; k<d; k++){
    dissqr += (x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
      }
      for(int l=1; l<130; l++){
        if(l*l == dissqr){
          num++;
        }
      }
    }
  }
  
  cout << num << endl;
  
}