
#include<bits/stdc++.h>
using namespace std;
int main(){
	stack<int> s; 
	char temp[7];
	int tmp;
	while(cin>>temp){
	if(temp[0]=='+'){
		//如果为操作符号的话
		int a=s.top();
		s.pop();
		int b=s.top();
		s.pop();
		tmp=b+a;
	}
	else if(temp[0]=='-'){
		int a=s.top();
		s.pop();
		int b=s.top();
		s.pop();
		tmp=b-a;
	}
	else if(temp[0]=='*'){
		int a=s.top();
		s.pop();
		int b=s.top();
		s.pop();
		tmp=b*a;
	}
	else if(temp[0]=='/'){
		int a=s.top();
		s.pop();
		int b=s.top();
		s.pop();
		tmp=b/a;
	}
	else{
		stringstream ss;
		ss<<temp;
		ss>>tmp;
	}
	s.push(tmp);
	}
	cout<<s.top()<<'\n';
	return 0;
}
