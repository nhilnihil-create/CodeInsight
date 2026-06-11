#include <bits/stdc++.h>
using namespace std;

 
int main() {
  int A, B, C, K;
  int x, y, t;
  cin >> A >> B >> C >> K;
  t= 0;
  while(A >= B){
      B = B*2;
      t++;
    }
  while(B >= C){
    C = C*2;
    t++;
    }
    
    if( t <= K ){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
    }
    
           
}
