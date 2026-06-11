#include <bits/stdc++.h>
using namespace std;

int main()
{
  int x;
  cin >> x;
  
  int fh = x / 500;
  x -= 500 * fh;
  
  int fo = x / 5;
  
  cout << fh * 1000 + fo * 5 << endl;
}