#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  vector<int> A;
  cin >> n >> k;
  A = vector<int>(n);
  for(int i = 0; i < n; i++) cin >> A[i];
  
  for(int i = 0; i < k; i++){
    vector<int> B(n,0);
    vector<int> C(n,0);
    for(int j = 0; j < n; j++){
      int s = max(0, j-A[j]);
      int e = min(j+A[j], n-1);
      B[s]++;
      if(e+1 < n) B[e+1]--;
    }
    C.at(0) = B.at(0);
    for(int j = 1; j < n; j++) C[j] = C[j-1] + B[j];
   
    if(A == C){
      for(int j = 0; j < n; j++){
        if(j) cout << " ";
        cout << A[j];
      }
      cout << endl;
      return 0;
    }
    
    for(int j = 0; j < n; j++) A[j] = C[j];
  }
  
  for(int i = 0; i < n; i++){
    if(i) cout << " ";
    cout << A[i];
  }
  cout << endl;
  
  return 0;
}