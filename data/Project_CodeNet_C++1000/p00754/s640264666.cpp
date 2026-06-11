

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <queue>
#include <map>
#include <stack>
using namespace std;
 
int dx[8]={1,-1,0,0,1,1,-1,-1};
int dy[8]={0,0,1,-1,-1,1,-1,1};
 
 
int main() {
string s;
	while(getline(cin,s)){
//		cout<<s<<endl;
		if(s==".") break;
	int ans=1;
	int l=s.length();
	stack<int> st; 
	for(int i=0;i<l;i++){
		if(s[i]=='(') st.push(1);
		else if(s[i]=='[') st.push(2);
		else if(s[i]==')'){
		if(st.empty()==true){
		ans=0;
		break;		
		}
		if (st.top()==1){
		st.pop();		
		}
		else{
		ans=0;
		break;
		}
		}

else if(s[i]==']'){
if(st.empty()==true){
		ans=0;
		break;		
		}
		if (st.top()==2){
		st.pop();		
		}
		else{
		ans=0;
		break;
		}
}
		}
	if(ans==1 && st.empty()==true) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	}


	return 0;
 
   }