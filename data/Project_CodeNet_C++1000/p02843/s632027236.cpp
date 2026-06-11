#include <bits/stdc++.h>
using namespace std;

int main() {
  int X;
  cin >> X;
  
  int Y=X/100;

  if(X%100<=Y*5){
  	cout << 1 << endl;
  }else{
  	cout << 0 << endl;
  }

  return 0;
}
