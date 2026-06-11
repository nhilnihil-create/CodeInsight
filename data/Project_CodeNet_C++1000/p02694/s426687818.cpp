#include <bits/stdc++.h>
using namespace std;
	
int main() {

  long long A;
  int B = 0;
  long long C = 100;
  cin >> A;
  while(C < A){
      C += C/100;
      B++;
  }
  cout << B <<endl;
  
}