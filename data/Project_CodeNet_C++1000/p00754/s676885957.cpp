#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main( void )
{
	string in;
	while(getline(cin, in), in[0] != '.') {
		stack<char> st;
		bool hit = true;
		int len = in.size();
		for(int i=0; i < len; ++i) {
			if(in[i] == '(' || in[i] == '[') {
				st.push(in[i]);
			}
			else if(in[i] == ')') {
				if(st.empty()) {
					hit = false;
				}
				else {
					if(st.top() != '(') hit = false;
					st.pop();
				}
			}
			else if(in[i] == ']') {
				if(st.empty()) {
					hit = false;
				}
				else {
					if(st.top() != '[') hit = false;
					st.pop();
				}
			}
		}
		if(st.size() == 0 && hit)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}