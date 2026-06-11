#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int X;
  cin >> X;
  if(X<600){
    cout << 8 << endl;
  }
  else if(600<=X && X<800){
    cout << 7 << endl;
  }
  else if(800<=X && X<1000){
    cout << 6 << endl;
  }
  else if(1000<=X && X<1200){
    cout << 5 << endl;
  }
  else if(1200<=X && X<1400){
    cout << 4 << endl;
  }
  else if(1400<=X && X<1600){
    cout << 3 << endl;
  }
  else if(1600<=X && X<1800){
    cout << 2 << endl;
  }
  else if(1800<=X && X<2000){
    cout << 1 << endl;
  }
}


