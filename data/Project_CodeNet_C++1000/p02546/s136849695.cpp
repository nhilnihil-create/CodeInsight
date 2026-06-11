#include <bits/stdc++.h>

using namespace std;

int main(){

 string s1;
 
 cin >> s1;

  char a, b;
  a = s1[s1.size()-1];
  b = 's';
   
  if( a == b ){
  cout << s1 << "es" << endl;
  }
  else{
  cout << s1 << "s" << endl;
  }
  
 return 0;
}