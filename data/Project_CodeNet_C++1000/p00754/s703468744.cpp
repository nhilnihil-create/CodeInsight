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

		for(int i=0 ; i < s.size() ; i++ ){
			char c = s[i];
			if( c == '(' || c == '[' ){
				st.push( c );
			}else if( s[i] == ')' ){
				if( st.empty() || st.top() == '[' ){
					flag = false;
					break;
				}else if( st.top() == '(' ){
					st.pop();
				}
			}else if( s[i] == ']' ){
				if( st.empty() || st.top() == '(' ){
					flag = false;
					break;
				}else if( st.top() == '[' ){
					st.pop();
				}
			}
		}
		if( flag && st.empty() )
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}