#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  if(s[1]=='R'){
    if(s[0]=='R' && s[2]=='R'){
      cout << 3;
    }
    else if(s[0]=='R' || s[2]=='R'){
      cout << 2 ;
    }
    else{
      cout << 1;
    }
  }
  else{
    if(s[0]=='R' || s[2]=='R'){
      cout << 1;
    }
    else {
      cout << 0;
    }
  }
   return 0;
}
    
    
    
    
    
    
    
    