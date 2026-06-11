#include<bits/stdc++.h>
using namespace std;

int main(){
  long long X,K,D;
  cin >> X >> K >> D;
  X=abs(X);
  long long A=X/D;
  long long B=K-A;
  if(A>=K){
    cout << X-D*K << endl;
  }
  else if(B%2==0){
    cout << X-D*A << endl;
  }
  else{
    cout << abs(X-D*A-D) << endl;
  }
}
  