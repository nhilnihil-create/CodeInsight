#include<iostream>
#include<string>
#include<stack>
#include<map>
using namespace std;

bool isBalance(string str){
	stack<char> st;
	map<char, char> m;
	m[')']='('; m[']']='[';
	for(int i=0;i<str.size();i++){
		if(str[i]=='(' || str[i]=='['){
			st.push(str[i]);
		}else if(str[i]==')' || str[i]==']'){
			if(st.size() > 0 && m[str[i]]==st.top()){
				st.pop();
			}else return false;
		}
	}
	return !(st.size() > 0);
}

int main(){
	string str;
	while(getline(cin,str)){
		if(str==".") break;
		if(isBalance(str)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}