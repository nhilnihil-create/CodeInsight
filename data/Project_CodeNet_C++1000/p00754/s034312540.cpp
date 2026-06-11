#include <iostream>
#include <string>
#include <stack>
using namespace std;

int check( string str ){
  stack <char> ch;
  int i;
  int len = str.size();
  for( i = 0; i < len; i++ ){
    if( !(str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']' ))continue;
    if( str[i] == '(' || str[i] == '[') ch.push(str[i]);
    else {
     
      if( ch.empty() ){
	  return 0;
	}
    
      if( ch.top() != '(' && str[i] == ')' ) return 0;
      else if( ch.top() == '(' && str[i] == ')' ) ch.pop();
      else if( ch.top() != '[' && str[i] == ']' ) return 0;
      else if( ch.top() == '[' && str[i] == ']' ) ch.pop();

    }
  }
    
  if( !( ch.empty() ) ) return 0;
  return 1;
}

int main(){
 
  string str;
  while( getline(cin,str) ){
    if( str == "." ) break;
    if( check(str) == 1 ) cout << "yes" << endl;
    else cout << "no" << endl;
  }

  return 0;
}