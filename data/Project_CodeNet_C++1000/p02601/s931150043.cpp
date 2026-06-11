#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C,X;
  cin >> A >> B >> C >> X;
  
  int b,c;
  
  for(int i=0;i<X;i++){
    if(A<B){
      break;
    }
    else{
      B*=2;
      b++;
    }
  }
  
  c=X-b;
  
  for(int i=0;i<c;i++){
    C*=2;
  }
  
  if(B<=A){
    cout << "No" << endl;
  }
  else if(B>=C){
    cout << "No" << endl;
  }
  else{
    cout << "Yes" << endl;
  }
}


