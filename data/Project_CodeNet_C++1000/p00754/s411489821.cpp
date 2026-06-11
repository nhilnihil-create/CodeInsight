#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
	while(true){
		string s;
		getline(cin, s);
		if(s == "."){ break; }
		stack<char> stk;
		bool success = true;
		for(int i = 0; i < s.size(); ++i){
			char c = s[i];
			if(c == '(' || c == '['){
				stk.push(c);
			}else if(c == ')'){
				if(stk.size() > 0 && stk.top() == '('){
					stk.pop();
				}else{
					success = false;
					break;
				}
			}else if(c == ']'){
				if(stk.size() > 0 && stk.top() == '['){
					stk.pop();
				}else{
					success = false;
					break;
				}
			}
		}
		if(success && stk.size() == 0){
			cout << "yes" << endl;
		}else{
			cout << "no" << endl;
		}
	}
	return 0;
}