#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

int main(){
	
	string str;
	
	while(true){
		
		getline(cin, str);
		
		if(str.size() == 1){
			break;
		}
		
		stack<int> sta;
		
		bool flag = true;
		
		for(int i = 0; i < str.size(); i++){
			if(str[i] == '('){
				sta.push(0);
			}else if(str[i] == '['){
				sta.push(1);
			}else if(str[i] == ')'){
				if(sta.empty()){
					flag = false;
					continue;
				}
				if(sta.top() != 0){
					flag = false;
				}
				sta.pop();
			}else if(str[i] == ']'){
				if(sta.empty()){
					flag = false;
					continue;
				}
				if(sta.top() != 1){
					flag = false;
				}
				sta.pop();
			}
		}
		
		if(!sta.empty()){
			flag = false;
		}
		
		if(flag){
			cout << "yes" << endl;
		}else{
			cout << "no" << endl;
		}
		
	}
	
	return 0;
}