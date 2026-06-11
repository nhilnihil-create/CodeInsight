#include <bits/stdc++.h>
using namespace std;
//cout << atan(1)*180/3.1415926535 << endl;
int main() {
double a,b,x;
  cin >> a >> b >> x;
  if(a * a * b == x){
  	cout << 0 << endl;
  }
  else{
    x = x/a;
    double c = 2*b-(2*x/a);
  	if(2*x/b <= a){
    	cout << fixed << setprecision(12) << 90-atan(2*x/b/b)*180/3.1415926535 << endl;
    }
    else{
    	cout << fixed << setprecision(12) << 90-atan(a/c)*180/3.1415926535 << endl;
    }
  }
}