#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
	string str;
	while(getline(cin,str) && str != "."){
		vector<char> c;
		for(int i = 0 ; i < str.size() ; i++)
			if(str[i] == ')' || str[i] == '(' || str[i] == '[' || str[i] == ']')
				c.push_back(str[i]);
		stack<char> s;
		bool f = true;
		for(int i = 0 ; i < c.size() ; i++)
			if(s.size() == 0 || c[i] == '(' || c[i] == '[')
				s.push(c[i]);
			else if(c[i] == ')' && s.top() == '('){
				s.pop();
			}else if(c[i] == ']' && s.top() == '['){
				s.pop();
			}else{
				f = false;
			}
			cout << (f && s.empty() ?"yes":"no") << endl;
	}
}