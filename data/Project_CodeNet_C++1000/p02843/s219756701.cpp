#include <bits/stdc++.h>
using namespace std;

int main() {
  int yen;
  int Max;
  int Min;
  cin >> yen;
  
  Max = yen / 100;
  Min = (yen % 100 + 4) / 5;
  
  if(Min <= Max){
    cout << 1;
  }else{
    cout << 0;
  }
}
