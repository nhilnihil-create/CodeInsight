#include <bits/stdc++.h>
using namespace std;

int main() {
 int a;
 int b;
 int c;
 int d;
 int e;
 cin >> a;
 cin >> b;
 cin >> c;
 if (0 == a % b){
   d = a / b;
   e = d * c;
   cout << e;
 }else{
   d = a / b;
   d = d + 1;
   e = d * c;
   cout << e;
 }
  
	return 0;
}
