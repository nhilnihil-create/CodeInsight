#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y;
  bool flag=false;
  cin >> X >> Y;
  for (int i=0; i<X+1; i++){
    if (4*X-2*i == Y){
      flag=true;
      break;
    }
  }
    if(flag)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
}