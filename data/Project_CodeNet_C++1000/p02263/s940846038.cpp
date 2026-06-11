#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
	stack<int> st;
	string str;
	while(cin >> str){
		char c = str[0];
		if(isdigit(c)){
			st.push(stoi(str));
		}else{
			int y = st.top();st.pop();
			int x = st.top();st.pop();
			if(c == '+'){
				st.push(x+y);
			}else if(c == '-'){
				st.push(x-y);
			}else if(c == '*'){
				st.push(x*y);
			}
		}
		cin.ignore();
	}
	cout << st.top() << endl;
	
	return 0;
}