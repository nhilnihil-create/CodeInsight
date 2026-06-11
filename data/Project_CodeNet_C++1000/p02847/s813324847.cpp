#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string W;
  cin >> W;
  
  if (W == "MON") {
    cout << 6 << endl;
  }
  else if (W == "TUE") {
    cout << 5 << endl;
  }
  else if (W == "WED") {
    cout << 4 << endl;
  }
  else if (W == "THU") {
    cout << 3 << endl;
  }
  else if (W == "FRI") {
    cout << 2 << endl;
  }
  else if (W == "SAT") {
    cout << 1 << endl;
  }
  else {
    cout << 7 << endl;
  }
}