#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
	string str;
	while (1){
		getline(cin, str);
		if (str[0] == '.' && str.length() == 1) break;

		stack <char> data;
		bool flag = true;
		data.push('*');
		for (int i = 0; i < (int)str.length(); i++){
			if (str[i] == '(' || str[i] == '[') data.push(str[i]);
			if (str[i] == ')'){
				if (data.top() == '(') data.pop();
				else flag = false;
			}
			if (str[i] == ']'){
				if (data.top() == '[') data.pop();
				else flag = false;
			}
		}
		if (data.top() == '*' && flag == true){
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}

	return 0;
}