#include <bits/stdc++.h>
using namespace std;

int main()
{
  int X,r;
  cin >> X;
  if(X<=599) r=8;
  else if(X<=799) r=7;
  else if(X<=999) r=6;
  else if(X<=1199) r=5;
  else if(X<=1399) r=4;
  else if(X<=1599) r=3;
  else if(X<=1799) r=2;
  else r=1;
  cout << r << endl;
}