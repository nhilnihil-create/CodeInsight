#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
	string s;
	while( getline(cin,s) ){
		if( s == "." ) break;

		stack<char> st;
		bool flag = true;
		for(int i=0 ; i < (int)s.size() ; i++ ){
			char c = s[i];
			if( c == '(' ){
				st.push( c );
			}else if( c == '[' ){
				st.push( c );
			}else if( c == ')' ){
				if( st.empty() ){
					flag = false;
					break;
				}else if( st.top() == '(' ){
					st.pop();
				}else{
					flag = false;
					break;
				}
			}else if( c == ']' ){
				if( st.empty() ){
					flag = false;
					break;
				}else if( st.top() == '[' ){
					st.pop();
				}else{
					flag = false;
					break;
				}
			}
		}
		if( st.empty() && flag ){
			cout << "yes" << endl;
		}else{
			cout << "no" << endl;
		}
	}
}