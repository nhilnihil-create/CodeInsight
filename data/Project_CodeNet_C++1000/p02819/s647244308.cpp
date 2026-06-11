#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long X,Y=0;
  bool S=true;
  cin >> X;
  for(Y=X;X>0;Y++){
    S=true;
    for(long long i=2;i<=Y/2;i++){
      if(Y%i == 0){
        S=false;
      }
    }
    if (S == true){
      break;
    }
  }
  cout << Y << endl;
}
