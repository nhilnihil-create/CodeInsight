#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string x;
  cin >> x;

  for(int i = 0; i < 3; i++) {
    if(x.at(i) == x.at(i+1)) {
      cout << "Bad" << endl;
      break;
    }
    else if(i == 2) cout << "Good" << endl;
  }

}