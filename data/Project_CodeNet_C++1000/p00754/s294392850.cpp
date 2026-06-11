#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool iscollect(string str){
	string::iterator fwd,last;
	stack<bool> list;
	bool ret=true;
	fwd=str.begin();
	last=str.end();
	while(fwd!=last){
		if(*fwd=='('){
			list.push(true);
		}else if(*fwd=='['){
			list.push(false);
		}else if(*fwd==')'){
			if(list.empty()||list.top()==false){
				ret=false;
				break;
			}
			list.pop();
		}else if(*fwd==']'){
			if(list.empty()||list.top()==true){
				ret=false;
				break;
			}
			list.pop();
		}
		++fwd;
	}
	if(!list.empty())ret=false;
	return ret;
}

int main(){
	string in;
	while(true){
		getline(cin, in);
		if(in==".")break;
		if(iscollect(in)){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
	}
	return 0;
}