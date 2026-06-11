#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<stack>
using namespace std; 
int main(){
  string s;
  while(getline(cin,s),s!="."){
    stack<int> a;
    for(int i=0;i<s.size();i++){
      if(s[i]=='('||s[i]=='['){
	a.push(s[i]);
      }
      else if(s[i]==')'){
	if(a.size()>0&&a.top()=='('){
	  a.pop();
	}else{
	  cout<<"no"<<endl;
	  goto at;
	}
      }
      else if(s[i]==']'){
	if(a.size()>0&&a.top()=='['){
	  a.pop();
	}else{
	  cout<<"no"<<endl;
	  goto at;
	}
      }
    }
    if(a.size()==0){
      cout<<"yes"<<endl;
    }else{
      cout<<"no"<<endl;
    }
  at: ;  
}
  
  return 0;
}