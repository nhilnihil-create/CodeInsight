#include<iostream>
#include<string>
#include<stack>
#include <cmath>
using namespace std;
bool paren(char a,char b){
	return (a=='('&&b==')')||(a=='['&&b==']');
}
int main(){
	string str;
	while(getline(cin,str)&&str!="."){
		int flg=1;
		stack<char> stk;
		for(unsigned i=0;i<str.size()&&flg==1;i++){
			switch(str[i]){
			case '(':
			case '[':
				stk.push(str[i]);
				break;
			case ']':
			case ')':
				if(stk.empty()||!paren(stk.top(),str[i])){
					flg=0;
				}
				if(flg)stk.pop();
			}
		}
		if(!stk.empty())flg=0;
		cout<<(flg==1?"yes":"no")<<endl;
	}
}