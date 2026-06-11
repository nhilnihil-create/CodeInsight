// 2012/05/14 Tazoe

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	while(true){
		string str;
		getline(cin, str);

		if(str==".")
			break;

		stack<char> S;

		bool flg = true;
		for(int i=0; flg&&str[i]!='.'; i++){
			if(str[i]=='('){
				S.push(str[i]);
			}
			else if(str[i]=='['){
				S.push(str[i]);
			}
			else if(str[i]==')'){
				if(S.empty()||S.top()!='('){
					flg = false;
				}
				else{
					S.pop();
				}
			}
			else if(str[i]==']'){
				if(S.empty()||S.top()!='['){
					flg = false;
				}
				else{
					S.pop();
				}
			}
		}

		if(flg&&S.empty()){
			cout << "yes" << endl;
		}
		else{
			cout << "no" << endl;
		}
	}

	return 0;
}