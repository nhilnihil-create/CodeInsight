#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  int X, Y;

  cin >> X >> Y;
  if (Y % 2 == 0 && Y >= 2 * X && Y <= 4 * X){
    cout << "Yes" << endl;
  }
  else{
      cout << "No" << endl;
  }
}
