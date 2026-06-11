#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int d1, d2;
  cin >> n;

  int count = 0;
  for (int i = 0; i < n; i++) {
    cin >> d1 >> d2;
    if (d1 == d2)
    {
      count++;
      if (count == 3) {
        break;
      }
    }
    else
    {
      count = 0;
    }
  }
  
  if (count == 3) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}
