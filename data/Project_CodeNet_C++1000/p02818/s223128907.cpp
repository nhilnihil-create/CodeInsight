#include <bits/stdc++.h>
using namespace std;

int main(){
 long long A,B,K;
  cin >> A >> B >> K;

  if(K<=A){
    cout << A-K << " " << B << endl;
  }
  
  else if(A+B>K && K>A){
    cout << "0 " << B-K+A << endl;
  }
  
  else if(K>=A+B){
    cout << "0" << " " << "0" << endl;
  }
}