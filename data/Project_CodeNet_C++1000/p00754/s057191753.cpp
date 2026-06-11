#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
	while(1){
		bool flag;
		flag = true;
		string str;
		stack<int> num;
		getline(cin,str);
		if(str==".")	break;
		for(int i=0;i<str.size();i++){
			if(str[i]=='[')	num.push(1);
			else if(str[i]==']'){
				if(num.size()==0){
					flag=false;
					break;
				}
				if(num.top()==1)	num.pop();
				else{
						flag=false;
						break;
				}
			}
			else if(str[i]==')'){
				if(num.size()==0){
					flag = false;
					break;
				}
				if(num.top()==2)	num.pop();
				else{
						flag=false;
						break;
				}
			}
			else if(str[i]=='(')	num.push(2);
			
		}
		if(num.size()==0&&flag)	cout << "yes\n";
		else	cout << "no\n";
	}
}
