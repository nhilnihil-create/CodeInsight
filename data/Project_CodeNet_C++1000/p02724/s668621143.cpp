#include<bits/stdc++.h>
using namespace std;
  
int main(){
  int X,A,B;
  cin >> X;
  A=X/500;
  X%=500;
  B=X/5;
  cout << 1000*A+5*B << endl;
}
  