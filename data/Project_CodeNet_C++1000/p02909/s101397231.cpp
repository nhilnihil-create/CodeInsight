#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s,a,b,c;
  cin >> s;
  a = "Sunny", b = "Cloudy", c = "Rainy";
  if(s == a)
    cout << b << endl;
  else if(s == b)
    cout << c << endl;
  else
    cout << a << endl;
}