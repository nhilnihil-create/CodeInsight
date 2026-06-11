#include <bits/stdc++.h>
using namespace std; 

int main(){
  long long X,K,D;
  cin >> X >> K >> D;
  X=abs(X);
  long long A=X/D;
  if(K<=A){
    cout << X-K*D << endl;
    return 0;
  }
  K-=A;
  X-=A*D;
  if(K%2==0){
    cout << X << endl;
  }
  else{
    cout << abs(X-D) << endl;
  }
}
  