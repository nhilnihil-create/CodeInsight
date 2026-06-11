#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int X,N,M=0;
  cin >> X >> N;
  int A=X,B=X;
  bool E=false,F=false;
  vector<int>vec(N);
  for (int i=0; i<N; i++){
    cin >>vec[i];
    if (vec[i]==X){
      M=1;
    }
  }
  if (M==0){
    cout << X << endl;
    return 0;
  }
    for (int i=0; i<100; i++){
      E=false,F=false;
      A -= 1;
      B += 1;
      for (int j=0; j<N; j++){
        if (vec[j] == A){
          E=true;
        }
      }
      for (int i=0; i<N; i++){
        if (vec[i]==B){
          F=true;
        }
      }
      if (E==false){
        break;
      }
      if (F==false){
        break;
      }
    }
    if(E==false){
      cout << A << endl;
    }
    else if(F==false){
      cout << B << endl;
    }
}
