#include <bits/stdc++.h>
using namespace std;
int main(){
	string input;
	while(1){
		getline(cin,input);
		if(input.length()==1&&input[0]=='.')break;
		stack<bool> data;
		bool f=true;
		for(int i=0;i<input.length();i++){
			if(input[i]=='[')data.push(true);
			if(input[i]==']'){
				if(data.empty()||!data.top()){
					f=false;
					break;
				}else data.pop();
			}
			if(input[i]=='(')data.push(false);
			if(input[i]==')'){
				if(data.empty()||data.top()){
					f=false;
					break;
				}else data.pop();
			}
		}
		if(f&&data.empty()){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
	}
}