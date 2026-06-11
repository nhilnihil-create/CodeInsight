#include <bits/stdc++.h>
using namespace std;

int main(){
  int x;
  cin >> x;
  if(360%x==0)	cout << (360/x);
  else cout << ((x*360)/__gcd(x,360))/x;
  return 0;
}
