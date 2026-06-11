#include <bits/stdc++.h>
using namespace std;

int main() {
  char a;
  cin >> a;
  bool capital = false;
  for(int i = 65; i < 91; i++) {
    if(a== (char)i) {
      capital = true;
      break;
    }
  }
  if(capital)
    cout << 'A' << endl;
  else
    cout << 'a' << endl;
}