#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
 int K,N;
  cin >> K >> N ;
 vector<int>A(N);
  vector<int>B(N);
  int maxB;
for(int i=0; i<N; i++){
  cin >> A[i];
 }
  for(int i=0; i<N-1; i++){
    B[i] = A[i+1]-A[i];
  }
  B[N-1] = A[0]+K-A[N-1];
  maxB = B[0];
  for(int i=0; i<N; i++){
    if(maxB < B[i]){
      maxB = B[i];
    }
  }
  cout << K-maxB;
  
    
   return 0;
}