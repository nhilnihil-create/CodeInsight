#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
  int m1, d1;
  int m2, d2;
  cin >> m1 >> d1;
  cin >> m2 >> d2;
  if (m1 != m2 && d2 == 1) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }
}
