#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int X,Y;
  cin >> X >> Y;
  
  X = (4 - X) * 100000;
  Y = (4 - Y) * 100000;
  
  if(X <= 0){
  	X = 0;
  }
  if(Y <= 0){
  	Y = 0;
  }
  if(X == 300000 && Y == 300000){
  	cout << X+Y+400000 << endl;
  }else{
  	cout << X+Y << endl;
  }
}