#include <bits/stdc++.h>
using namespace std;

int main(){
  long long X;
  cin >> X;
  
  long long money = 100;
  for (int i=1 ; ; i++){
    money += money/100;
    if (money >= X){
      cout << i << endl;
      break;
    }
  }
}