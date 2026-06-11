#include<iostream>
#include<stack>
#include<string>
using namespace std ;

int main(){
	
	string s ;
	
	while( getline( cin , s ) ){
		if( s[0] == '.' ) break ;
		
		stack<int> st ;
		int t = 0 ;
		
		for( int i=0 ; i<s.size() ; i++ ){
			if( s[i] == '(' ) st.push(1) ;
			if( s[i] == '[' ) st.push(2) ;
			
			if( s[i] == ')' ){
				if( st.size() > 0 && st.top() == 1 ){
					st.pop() ;
				}
				else t = 1 ;
			}
			if( s[i] == ']' ){
				if( st.size() > 0 && st.top() == 2 ){
					st.pop() ;
				}
				else t = 1 ;
			}
			
			if( t == 1 ) break ;
		}
		
		if( t == 1 || st.size() > 0 ) cout << "no" << endl ;
		else cout << "yes" << endl ;
	}
	
return 0;
}