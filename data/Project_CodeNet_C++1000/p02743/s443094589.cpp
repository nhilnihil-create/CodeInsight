#include <iostream>
 #include <cmath>

 using namespace std;
 typedef long long ll;

 int main(void){
 long double a,b,c;
 cin >> a >> b >> c;

 long double eps = 1.0E-14;

 if(sqrt(a) + sqrt(b) + eps < sqrt(c)){
 cout << "Yes" << endl;
 } else {
 cout << "No" << endl; }

 return 0;
 }
