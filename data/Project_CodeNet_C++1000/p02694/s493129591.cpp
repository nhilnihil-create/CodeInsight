#include <bits/stdc++.h>
using namespace std;

int main() {
  long long X;
  cin >> X;
  long long Y = 100;
  int count = 0;
  long long risoku;
  
  while (Y < X){
    risoku = Y/100;
    Y += risoku;
    count++;
  }
  cout << count << endl;
}