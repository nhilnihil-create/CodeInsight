#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){

	string str;

	while(1){
		getline(cin,str);
		stack<int> data;
		if(str.at(0)=='.')break;

		int flag=0;
	
		for(int i=0;i<str.size();i++){

		if(str.at(i) =='('){
			data.push(1);
		}

		if(str.at(i) == '['){
			data.push(2);
		}

		if(str.at(i) ==')'){
			if(data.size()==0){
				cout<<"no"<<endl;
				flag=1;
			}
			else if(data.top() != 1){
				cout<<"no"<<endl;
				flag=1;
			}
			else{
				data.pop();
			}
		}
		if(str.at(i) == ']'){
			if(data.size()==0){
				cout<<"no"<<endl;
				flag=1;
			}
			else if(data.top() != 2){
				cout<<"no"<<endl;
				flag=1;
			}
			else{
				data.pop();
			}
		}

		if(flag==1)break;
		}

		if(flag==1)continue;

		if(data.size()!=0){
			cout<<"no"<<endl;
			continue;
		}

		cout<<"yes"<<endl;
	}

	return 0;
}