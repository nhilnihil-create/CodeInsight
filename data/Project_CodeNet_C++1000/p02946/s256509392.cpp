#include <bits/stdc++.h>
using namespace std;

int main() {
  int e,z;
  cin >> e >> z;
  z = z - e + 1;
  for(int i = 0; i < e * 2 - 1; i++){
    if(i == e * 2 -2){
      cout << z + i << endl;
      return 0;
    }
    else{
    cout << z + i << " ";  
    }
  }
  return 0;
}