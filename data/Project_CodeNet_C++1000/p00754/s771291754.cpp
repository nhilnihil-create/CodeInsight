#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	char c;

	while(1){
		cin.get(c);
		if(c=='.') break;
			
		stack<char> s;
		if(c=='(' || c=='[') s.push(c);
		else if(c==')' || c==']') s.push(c);

		while(1){
			cin.get(c);
			if(c=='.') {
				cin.get(c);
				if(c=='\n') break;
			}

			if(c=='(' || c=='[') s.push(c);
				
			else if(c==')'){
				if(!s.empty() && s.top()=='(') s.pop();
				else s.push(c);
			}
			else if(c==']'){
				if(!s.empty() && s.top()=='[') s.pop();
				else s.push(c);
			}
		}

		if(s.empty()) cout << "yes" << endl;
		else cout << "no" << endl;

	}

	return 0;
} 