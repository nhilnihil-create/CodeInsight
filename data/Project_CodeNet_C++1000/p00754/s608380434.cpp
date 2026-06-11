#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

int main(){
	while(1){
		string str; getline(cin,str);
		stack<char> st ;
		if (str == ".") break;
		//cout << str.size() << endl;
		//cout << str << endl;
		for (int i = 0; i < str.size(); i++){
			if (str[i] == '('){
				st.push(str[i]);
			}else if (str[i] == '['){
				st.push(str[i]);
			}else if (str[i] == ')'){
				if (st.empty()){
					st.push(str[i]);
				}else if (st.top() == '('){
					st.pop();
				}else{
					st.push(str[i]);
				}
			}else if (str[i] == ']'){
				if (st.empty()){
					st.push(str[i]);
				}else if (st.top() == '['){
					st.pop();
				}else{
					st.push(str[i]);
				}
			}
		}
		if (st.empty()){
			cout << "yes" << endl;
		}else{
			cout << "no" << endl;
		}
	
	}
return 0;
}