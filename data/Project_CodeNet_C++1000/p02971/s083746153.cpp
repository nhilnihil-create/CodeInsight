#include <bits/stdc++.h>
using namespace std;
 
int main() {
int N;
  cin >> N;
  vector<int> A(N);
  vector<int> B(N);
  for(int a = 0;a < N;a++){
    cin >> A[a];
    B[a] = A[a];
  }
  
  sort(A.begin(),A.end());
  if(A[N-1] == A[N-2]){
   for(int a = 0;a < N;a++)cout << A[N-1] << endl; 
    
  }else{
   for(int a = 0;a < N;a++){
    if(B[a] == A[N-1]){
     cout << A[N-2] << endl; 
    }else{
      cout << A[N-1] << endl; 
    }
     
     
   }
    
    
  }
}