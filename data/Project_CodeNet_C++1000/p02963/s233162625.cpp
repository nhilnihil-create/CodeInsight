#include<iostream>
#include<vector>
using namespace std;

typedef long long int ll;

int main(){
  ll S, x1,y1,x2,y2,x3,y3;
  cin >> S;
  x1 = y1 = 0;
  x2 = 1e9;
  x3 = 1;
  y3 = S / x2;
  if(S % x2 != 0)y3++;
  y2 = x2 * y3 - S;
  cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << x3 << ' ' << y3 << endl;
  return 0;
}
