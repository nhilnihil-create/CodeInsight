// 2013/06/20 Tazoe

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	while(true){
		string S;
		getline(cin, S);

		if(S==".")
			break;

		stack<char> stk;

		bool flg = true;
		for(int i=0; i<S.size(); i++){
			if(S[i]=='('||S[i]=='['){
				stk.push(S[i]);
			}
			else if(S[i]==')'){
				if(!stk.empty()&&stk.top()=='('){
					stk.pop();
				}
				else{
					flg = false;
				}
			}
			else if(S[i]==']'){
				if(!stk.empty()&&stk.top()=='['){
					stk.pop();
				}
				else{
					flg = false;
				}
			}

			if(!flg)
				break;
		}

		if(flg&&stk.empty()){
			cout << "yes" << endl;
		}
		else{
			cout << "no" << endl;
		}
	}

	return 0;
}