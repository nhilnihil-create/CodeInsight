#include <bits/stdc++.h>
using namespace std;

int main() {
  int X;
  cin >> X;
  int z = 360;
  for(int i=0; i<360; i++){
    if(z%X == 0){
      cout << z/X << endl;
      return 0;
    }
    else{
      z += 360;
    }
  }
}
