#include <bits/stdc++.h>
using namespace std;
int main(){
  int X = 0;
  cin >> X;
  if ((400 <= X) && (X < 600)){
    cout << "8" << endl;
  }
  if (600 <= X && X < 800){
    cout << "7" << endl;
  }
  if (800 <= X && X < 1000){
    cout << "6" << endl;
  }
  if (1000 <= X && X < 1200){
    cout << "5" << endl;
  }
  if (1200 <= X && X < 1400){
    cout << "4" << endl;
  }
  if (1400 <= X && X < 1600){
    cout << "3" << endl;
  }
  if (1600 <= X && X < 1800){
    cout << "2" << endl;
  }
  if (1800 <= X && X < 2000){
    cout << "1" << endl;
  }
  return 0;
}