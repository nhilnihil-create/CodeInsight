#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B;
  cin >> A >> B;
  
  if (B == 1){
    cout << 0 << endl;
    return 0;
  }
  
  int i = 0;
  while(true){
    if ((A - 1) * (i + 1) + 1 >= B){
      cout << i + 1 << endl;
      return 0;
    }
    i++;
  }
}