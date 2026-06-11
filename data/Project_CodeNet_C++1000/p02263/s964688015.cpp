
#include<iostream>
#include<sstream>
#include<stack>
#include<string>
using namespace std;
int main(){
	string t;
	int tmp,ans=0,t1,t2;
	stack<int>sta;
	
	while(cin>>t){
		
		if(t[0]=='-'||t[0]=='+'||t[0]=='*'){
			t2=sta.top();
			sta.pop();
			t1=sta.top();
			sta.pop();
			if(t[0]=='-')sta.push(t1-t2);
			if(t[0]=='+')sta.push(t1+t2);
			if(t[0]=='*')sta.push(t1*t2);
		}

		else{
			stringstream ss(t);
			ss>>tmp;
			sta.push(tmp);
		}
	
	}
	cout<<sta.top()<<endl;
		sta.pop();
	return 0;
}