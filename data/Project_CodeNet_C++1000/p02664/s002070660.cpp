#include <iostream>
#include <string.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  if(s.find("?") == string::npos){
    cout << s;
    //cout << "? ga naiyo\n";
    return 0;
  }
  
  size_t position_Phatena = 0;
  size_t position_2hatena = 0;
  size_t position_hatenaD = 0;
  size_t position_hatena = 0;
  
  while(s.find("?") != string::npos){
//    if((position_Phatena = s.find("P?") ) != string::npos){
//    	s[position_hatenaD+1] = 'D';
//    } 
//  	if( (position_2hatena = s.find("??") ) != string::npos){
//      s[position_2hatena] = 'P';
//      s[position_2hatena+1] = 'D';
//    }
//    if((position_hatenaD = s.find("?D") ) != string::npos){
//    	s[position_hatenaD] = 'P';
//    }
    if( (position_hatena = s.find("?") ) != string::npos){
    	s[position_hatena] = 'D';
    }
  }
  
//  cout << s.find("??") << endl;
  
  cout << s;
  
  return 0;
}