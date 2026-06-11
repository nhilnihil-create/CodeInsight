#include <bits/stdc++.h>
using namespace std;
int main(void){
   
  int N,c=0;
  cin >> N;
  int A[N],B[N],C[N-1];
  
  for(int i=0;i<N;i++) cin >> A[i];
  for(int i=0;i<N;i++) cin >> B[i];
  for(int i=0;i<N-1;i++) cin >> C[i];

  for(int i=0;i<N;i++){
      c +=  B[A[i]-1];
      if(i != 0 && A[i] - A[i-1] == 1) c+= C[A[i-1]-1];
  }
  cout << c << endl;
}