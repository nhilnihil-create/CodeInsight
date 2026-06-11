#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	while(1){
		getline(cin, s);
		if(s == ".")
			break;
		stack<char> k;
		bool ok = true;
		for(int i = 0; i < s.size(); ++i){
			if(s[i] == '('){
				k.push('(');
			}
			else if(s[i] == ')'){
				if(k.empty()){
					ok = false;
					break;
				}
				char c = k.top();
				k.pop();
				if(c != '('){
					ok = false;
					break;
				}
			}
			else if(s[i] == '['){
				k.push('[');
			}
			else if(s[i] == ']'){
				if(k.empty()){
					ok = false;
					break;
				}
				char c = k.top();
				k.pop();
				if(c != '['){
					ok = false;
					break;
				}
			}
		}
		if(k.empty() && ok){
			cout << "yes" << endl;
		}
		else{
			cout << "no" << endl;
		}
	}
	return 0;
}