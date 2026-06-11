#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  if (y % 2 == 1){
    cout << "No" << endl;
  }
  else {
  	int min = (y / 4) + (y - 4 * (y / 4)) / 2;
    int max = y /2;
    if (min <= x && x <= max){
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
}

