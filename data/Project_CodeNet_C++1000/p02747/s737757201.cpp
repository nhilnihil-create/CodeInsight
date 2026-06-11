#include <bits/stdc++.h>
using namespace std;

int main() {
  string u;
  char h,j;
  int len,deff = 0;
  cin >> u;
  h = 'h';
  j = 'i';
  len = u.length();
  if (len % 2 == 1)
  {
    deff = 1;
  }
  for (int i = 0; i < len; ++i)
  {
    if (i % 2 == 0) {
      if (u[i] != h) {
        deff = 1;
      } 
    } else {
      if (u[i] != j) {
        deff = 1;
      } 
    }
  }
  if (deff == 0)
  {
    cout << "Yes";
  } else {
    cout << "No";
  }
}