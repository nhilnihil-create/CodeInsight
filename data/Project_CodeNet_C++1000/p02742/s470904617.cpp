#include <iostream>
using namespace std;

int main() {
 long long a,b; cin >> a >> b;
 
  if(a == 1 || b == 1) {
    cout << "1" << endl;
    return 0;
  }
  
 long long multi = a * b;
 int mod = multi % 2;
 if(mod == 0) {
   cout << multi / 2 << endl;
 } else {
   cout << (multi / 2) + 1 << endl;
 }
  
 return 0; 
}