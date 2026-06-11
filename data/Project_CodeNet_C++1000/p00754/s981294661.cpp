#include<iostream>
#include<string>
#include<stack>
using namespace std;

//A rope may form )( a trail in a maze.

int main(){
	while(1){
		string data;
		for(char in = 0;in != '.';){
			in = cin.get();
			data += in;
		}
		cin.get();
		if(data == ".") break;
		
		stack<char> stk;
		int pc = 0;
		while(1){
			char in = data[pc];
			pc++;
			
			if(in == '(' || in == '['){
				stk.push(in);
			}
			if(in == ')' || in == ']'){
				if(stk.empty()){
					cout << "no" << endl;
					break;
				}
				char begin = stk.top();
				if((begin == '(' && in != ')') || (begin == '[' && in != ']')){
					cout << "no" << endl;
					break;
				}else{
					stk.pop();
				}
			}
			if(in == '.'){
				if(stk.empty()){
					cout << "yes" << endl;
				}else{
					cout << "no" << endl;
				}
				break;
			}
		}
	}
	
	return 0;
}