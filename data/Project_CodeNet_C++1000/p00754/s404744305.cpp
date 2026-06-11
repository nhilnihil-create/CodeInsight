#include <bits/stdc++.h>
using namespace std;

int main(void){
	string str;
	while(1){
		getline(cin, str);
		bool flg = true;
		if(str == ".") break;

		stack<char> q;
		for(int p=0; p < str.length(); p++){
			if(str[p] == '('){
				q.push('(');
			}
			if(str[p] == '['){
				q.push('[');
			}
			if(str[p] == ')'){
				if(q.empty() || q.top() != '('){
					flg = false;
					break;
				}else{
					q.pop();
				}
			}
			if(str[p] == ']'){
				if(q.empty() || q.top() != '['){
					flg = false;
					break;
				}else{
					q.pop();
				}
			}
		}
		if(q.empty() && flg) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}