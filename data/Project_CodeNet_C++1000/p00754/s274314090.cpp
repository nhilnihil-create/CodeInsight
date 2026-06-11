#include <bits/stdc++.h>
using namespace std;

int main(){
  string str;
			
  while(getline(cin, str)){
	if(str == ".") break;
	//cout << str << endl;
	bool flag  = false;
	stack<char> s;
	
	for(int i = 0; i < str.size(); i++){
	  if(str[i] == '(') s.push(str[i]);
	  else if(str[i] == '[') s.push(str[i]);
	  else if(str[i] == ')'){
		if(s.empty()){
		  flag = true;
		  break;
		}
		
		char tmp = s.top(); s.pop();
		//cout << "if ')' then tmp = " << tmp << endl;
		if(tmp != '('){
		  flag = true;
		  break;
		}
	  }
	  else if(str[i] == ']'){
		if(s.empty()){
		  flag = true;
		  break;

		}
		char tmp = s.top(); s.pop();
		//cout << "if ']' then tmp  = " << tmp << endl;
		if(tmp  != '['){
		  flag = true;
		  break;
		}
	  }
	}
	
	if(flag || !s.empty()) cout << "no" << endl;
	else cout << "yes" << endl;
  }
  return 0;
}