#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >> s;
  
  char a, b, c, d;
  a = s.at(0);
  b = s.at(1);
  c = s.at(2);
  d = s.at(3);
  
  if(a == b && b == c && c == d){
    cout << "No";
  }
  else if(a == b && c == d){
    cout << "Yes";
  }
  else if(a == c && b == d){
    cout << "Yes";
  }
  else if(a == d && b == c){
    cout << "Yes";
  }
  else{
    cout << "No";
  }
}