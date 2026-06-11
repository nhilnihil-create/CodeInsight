#include <bits/stdc++.h>
using namespace std;

int main() {
 int num;
 cin >> num;
  
 int temp;
 temp = num * 100 / 108;
 if(temp * 108 / 100 == num ) {
   cout << temp << endl;
 } else if( (temp + 1) * 108 / 100 == num) {
   cout << temp + 1 << endl;
 } else {
   cout << ":(" << endl;
 }
 
 return 0; 
}