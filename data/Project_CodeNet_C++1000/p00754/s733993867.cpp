#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
	while(1){		
		string str;
		getline(cin, str);
		if(str[0] == '.') break;
	/*	//string::iterator ite = str.end()--;
		if(str[str.size()-1] != '.'){
			while(1){
				string s;
				cin >> s;
				str.append(s);
				//ite = s.end()--;
				if(s[s.size()-1] == '.') break;
			}
		}
*/
		stack<char> sta;
		string s = "yes";
		for(int i = 0;str[i] != '.'; i++){
			if(str[i] == '(' || str[i] == '['){
				sta.push(str[i]);
			}else if(str[i] == ')'){
				if(sta.empty()){
					s = "no"; break;
				}
				if(sta.top() == '('){
					sta.pop();
				}else{
					s = "no"; break;
				}
			}else if(str[i] == ']'){
				if(sta.empty()){
					s = "no"; break;
				}
				if(sta.top() == '['){
					sta.pop();
				}else{
					s = "no"; break;
				}
			}
		}
		if(!sta.empty()) s = "no";

		cout << s << endl;
	}
	return 0;
}