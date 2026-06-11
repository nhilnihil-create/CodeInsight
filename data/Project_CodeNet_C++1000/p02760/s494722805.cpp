#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a[9];
  for (int i = 0; i < 9; i++)
    cin >> a[i];
  
  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; i++)
    cin >> b[i];
  
  vector<bool> c(9, false);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 9; j++) {
      if (b[i] == a[j])
        c[j] = true;
    }
  }
  
  int d[8][3] = {
    {0,1,2},
    {3,4,5},
    {6,7,8},
    {0,3,6},
    {1,4,7},
    {2,5,8},
    {0,4,8},
    {2,4,6}};
  
  bool fin = false;
  for (int i = 0; i < 8; i++) {
    if( c.at(d[i][0]) && c.at(d[i][1]) && c.at(d[i][2]) ) {
      cout << "Yes" << endl;
      fin = true;
      break;
    }
  }
  
  if (!fin)
    cout << "No" << endl;
}