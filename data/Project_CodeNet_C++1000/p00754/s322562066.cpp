#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
	string str;
	int i;
	
	while(1){
		getline(cin, str);
		if(str == ".")
			break;
		stack<char> tmp;
		tmp.push('$');
		for(i = 0; i < str.size(); i++){
			if(str[i] == '(' || str[i] == '[')
				tmp.push(str[i]);
			
			else if(str[i] == ')'){
				if(tmp.top() == '(')
					tmp.pop();
				else break;
			}
			
			else if(str[i] == ']'){
				if(tmp.top() == '[')
					tmp.pop();
				else break;
			}
		}
		if(i == str.size() && tmp.size() == 1)
			cout << "yes" << endl;
		else cout << "no" << endl;
	}
	
	return 0;
}