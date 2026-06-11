#include<bits/stdc++.h>
using namespace std;

#define ll long long

signed main()
{
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int X = (a+d-1)/d;
  int Y = (c+b-1)/b;
  cout << ((X>=Y)? "Yes":"No");
}