#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  
  int n = s.size();
  for(int i = 0; i < n; i++){
    if( (i % 2 == 1) && (s[i] != 'L' && s[i] != 'U' && s[i] != 'D') ){
      cout << "No" << endl;
      return 0;
    }else if( (i % 2 == 0) && (s[i] != 'R' && s[i] != 'U' && s[i] != 'D') ){
      cout << "No" << endl;
      return 0;
    }
  }
  
  cout << "Yes" << endl; 
      
}