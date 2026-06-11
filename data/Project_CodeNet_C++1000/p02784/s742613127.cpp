#include<bits/stdc++.h>
using namespace std;

int main()
{
  int h, n;
  cin >> h >> n;
  
  int a;
  bool canWin = false;
  for (int i = 0; i < n; i++) {
    cin >> a;
    h -= a;
    if (h <= 0) {
      canWin = true;
      break;
    }
  }
  
  cout << (canWin ? "Yes" : "No") << endl;
}