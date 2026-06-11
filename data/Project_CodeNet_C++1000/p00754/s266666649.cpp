#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int main()
{
	stack<char> s;

	while (true){
		char str[128];
		fgets(str, sizeof(str), stdin);

		if (str[0] == '.'){
			break;
		}

		while (!s.empty()){
			s.pop();
		}

		bool flag = true;
		for (int i = 0; str[i] != '.'; i++){
			if (str[i] == '(' || str[i] == '['){
				s.push(str[i]);
			}

			if (str[i] == ')'){
				if (s.empty()){
					flag = false;
					break;
				}
				else if (s.top() == '('){
					s.pop();
				}
				else if (s.top() == '['){
					flag = false;
					break;
				}
			}
			if (str[i] == ']'){
				if (s.empty()){
					flag = false;
					break;
				}
				else if (s.top() == '['){
					s.pop();
				}
				else if (s.top() == '('){
					flag = false;
					break;
				}
			}
		}

		if (flag && s.empty()){
			puts("yes");
		}
		else {
			puts("no");
		}
	}

	return (0);
}