#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	string str;
	while (1){
		getline(cin,str);
		if (str[0] == '.') break;
		string ans = "yes";
		stack<char> L;
		for (int i = 0; i < str.size(); i++){
			if (str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']'){
				if (str[i] == '(' || str[i] == '['){
					L.push(str[i]);
					continue;
				}
				if (L.empty() == false){
					if (str[i] == ')' && L.top() == '('){
						L.pop();
						continue;
					}
					if (str[i] == ']' && L.top() == '['){
						L.pop();
						continue;
					}
				}
				ans = "no";
				break;
			}
		}
		if (L.empty() == false){
			ans = "no";
		}
		cout << ans << endl;
	}
	return 0;
}