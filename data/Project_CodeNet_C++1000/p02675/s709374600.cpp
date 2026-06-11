#include <bits/stdc++.h>
using namespace std;

int main() {
 int N,X;
 cin >> N;
 X = N % 10;
  
  if(X == 2||X == 4||X == 5||X == 7||X == 9){
    cout << "hon" << endl;
  }
  if(X == 0||X == 1||X == 6||X == 8){
    cout << "pon" << endl;
  }
  if(X == 3){
    cout << "bon" << endl;
  }
}