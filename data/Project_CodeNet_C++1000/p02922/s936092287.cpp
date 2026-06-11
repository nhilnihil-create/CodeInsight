#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C,N;
    cin >> A >> B;
  C = 1;
  N = 0;
 if (B == 1){
 cout << 0 << endl;
 }
  else if (B <= A){
  cout << 1 << endl;
  }
  else if(B > A) {while (C < 21){
    
  N = A + (A-1) * (C-1);
    
  if(B <= N){
    cout << C << endl;
    break;
  }
    C++;
}
                  }  
}
