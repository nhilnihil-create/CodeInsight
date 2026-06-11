#include <iostream>
#include <string>
#include <stack>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  char s[256],c ;
  string st;
  int len, i;
  stack<char> stack;

  while( true ){
    fgets( s,255,stdin );
    st = s;
    len = st.length();
    if( st[len-1]=='\n' ) st[--len]='\0';

    if( len==1 && st[0]=='.' ) break;
    //    cout << st << endl;

    while( !stack.empty() ) stack.pop();

    for( i=0;i<len;i++ ){
      c = st.at(i);
      switch( c ){
      case '(':
      case'[': stack.push( c ); break;
      case ')':
	if( stack.empty() ){
	  stack.push( c );	  i=len;
	}else{
	  if( stack.top()=='(' ) stack.pop();
	  else i=len;
	}
	break;
      case ']':
	if( stack.empty() ){
	  stack.push( c );	  i=len;
	}else{
	  if( stack.top()=='[' ) stack.pop();
	  else i=len;
	}
	break;
      default :
	break;
      }
    }

    if( stack.empty() ) cout << "yes"<<endl;
    else         cout << "no"<<endl;
  }
  return 0;
}