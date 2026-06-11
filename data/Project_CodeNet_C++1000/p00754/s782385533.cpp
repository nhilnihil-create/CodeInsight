#include<bits/stdc++.h>
using namespace std;

string str;

int main(){
  while( getline(cin,str) ){
    if( str[0] == '.' ) break;

    stack<char> st;

    for(int i=0;i<(int)str.size();i++){
      if( str[i] == '(' || str[i] == '[' ){
	st.push( str[i] );
      } else if( str[i] == ')' ){
	if( st.empty() ) {
	  st.push(str[i]); break;
	}
	if( st.top() == '(' ) st.pop();
	else break;
      } else if( str[i] == ']' ){
	if( st.empty() ) {
	  st.push(str[i]); break;
	}
	if( st.top() == '[' ) st.pop();
	else break;
      }
    }

    if( st.empty() ) cout << "yes" << endl;
    else cout << "no" << endl;

  }
}