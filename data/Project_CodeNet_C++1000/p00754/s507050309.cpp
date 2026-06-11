#include <iostream>
#include <stack>
using namespace std;

int main() {
	
	while(true){
		string str;
		getline( cin, str);
		if( str == "." ) break;
		stack<char> s;
		
		bool yes = true;
		for(char c : str){
			if( c=='(' || c=='['){
				s.push(c);
			}
			else if( c==')'){
				if( s.empty() || s.top() != '(' ){
					yes=false;
					break;
				}
				s.pop();
			}
			else if( c==']'){
				if( s.empty() || s.top() != '[' ){
					yes=false;
					break;
				}
				s.pop();
			}
		}
		if(!s.empty()) yes=false;
		cout << (yes?"yes":"no") << endl;
	}
	return 0;
}