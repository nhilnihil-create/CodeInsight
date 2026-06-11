#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s, t, h;
  cin >> s >> t;
  int c, d;
  cin >> c >> d;
  cin >> h;
  if(s == h) {
    c--;
  } else {
    d--;
  }
  printf("%d %d", c, d);
}