#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; (int)(n); i++)
 
 int main() {
  string text;
  cin >> text;
  
  if (text.back() == 's') {
    cout << text << "es" << endl;
  } 
  else {     
    cout << text << "s" << endl;
  }   
}