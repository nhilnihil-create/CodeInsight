#include<bits/stdc++.h>
using namespace std;

int main(){
  double a, b, h, m; cin >> a >> b >> h >> m;
  
  double pi = 2*asin(1);
  
  double thita = abs(60*h-11*m)*pi/360;
  
  double l = a*a + b*b - 2*a*b*cos(thita);
  
  cout << fixed << setprecision(20);
  cout << sqrt(l) << endl;
}