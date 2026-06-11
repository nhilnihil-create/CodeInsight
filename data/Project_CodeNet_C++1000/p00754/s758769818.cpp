#include <iostream>
#include <iomanip>
#include <cstring>
#include <stack>
using namespace std;

int main(){
	string str;
	while(getline(cin,str)){
		stack<int> st;
		bool ok = true;
		if(str.size() == 1 && str[0] == '.') break;
		for(int i = 0; i < str.size(); i++){
			if(str[i] == '(') st.push(1);
			else if(str[i] == '[') st.push(2);
			else if(str[i] == ')'){
				if(st.size()==0||st.top() != 1){
					ok = false;
					break;
				} else{
					st.pop();
				}
			}
			else if(str[i] == ']'){
				if(st.size()==0||st.top() != 2){
					ok = false;
					break;
				} else{
					st.pop();
				}
			}
		}
		if(st.size() != 0) ok = false;
		if(ok) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}