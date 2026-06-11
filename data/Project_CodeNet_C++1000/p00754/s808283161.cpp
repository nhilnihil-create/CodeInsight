// AOJ 1173

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	while (1){
		string str;
		getline(cin, str);
		if (str == "."){
			break;
		}
		
		stack <char> st;
		bool flag = true;
		for (int i = 0; i < str.length(); i++){
			if (str[i] == '(' || str[i] == '['){
				st.push(str[i]);
			}
			if (str[i] == ')'){
				if (st.size() == 0 || st.top() == '['){
					flag = false;
				}
				else if (st.top() == '('){
					st.pop();
				}
			}
			if (str[i] == ']'){
				if (st.size() == 0 || st.top() == '('){
					flag = false;
				}
				else if (st.top() == '['){
					st.pop();
				}
			}
		}
		if (st.size() == 0 && flag){
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
	
	return 0;
}