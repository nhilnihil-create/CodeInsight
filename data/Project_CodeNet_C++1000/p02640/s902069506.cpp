#include <bits/stdc++.h>
using namespace std;

int main() {
 int X,Y;
  cin >> X >> Y;
  bool ans = false;
  for(int i = 0; i < Y; i++){
    for(int j = 0; j < Y ;j++){
      if(i + j == X && 4*i + 2*j == Y){
      ans = true;}
}
  }
  if(ans){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}