#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, X, T;
  cin >>N >>X >>T;
  
  int numbers;
  
  if (N % X == 0) {
  	numbers = N / X;
  }
  
  else {
    numbers = N / X + 1;
  }
  
  cout << numbers * T << endl;
}