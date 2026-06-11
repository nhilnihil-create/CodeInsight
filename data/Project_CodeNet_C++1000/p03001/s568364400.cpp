#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
double PI = 3.1415926535897932;
long mod = 1000000007;

const long INF = 1e9 + 1;

int main() {
  double w,h,x,y;
  cin >> w >> h >> x >> y;  
  cout << fixed << setprecision(12) << w*h/2;

  if(x*2 == w & y*2 == h) 
    cout << " " << 1 << endl;
  else cout << " " << 0 << endl;
}
