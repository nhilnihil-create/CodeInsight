#include <iostream>
#include <stack>
#include <string>

#define rep(i, n) for(int i = 0; i < n; i ++)

using namespace std;

int main(void){
	for(string in; getline(cin, in) && in != ".";){
		stack<char> table;
		string out = "yes";

		rep(i, in.length()){
			char curChar = in.at(i);
			if(curChar == '[' || curChar == '(') table.push(curChar);
			else if(curChar == ']'){
				if(!table.empty() && table.top() == '[') table.pop();
				else{ out = "no"; break; }
			}
			else if(curChar == ')'){
				if(!table.empty() && table.top() == '(') table.pop();
				else{ out = "no"; break; }
			}
		}
		if(!table.empty()) out = "no";
		cout << out << endl;
	}

	return 0;
}