#include <bits/stdc++.h>

using namespace std;
int main(){
  int x;
  cin >> x;
  int k = 1;
  while(1)
  {
    if((k * x) % 360 == 0){
      cout << k << endl;
      break;
    }
    k++;
  }
}