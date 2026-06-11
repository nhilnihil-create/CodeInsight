#include<iostream>
#include<stack>
using namespace std;

int main(){
  string str;
  stack<char> s;
  int f;
  while(1){
    f=0;
    getline(cin,str);

     if(str[0]=='.') break;

    for(int i=0;i<str.size();i++){
      if(str[i]=='(' || str[i]=='[') s.push(str[i]);
      else if(str[i]==')' || str[i]==']'){
	if( s.empty()!=1 && str[i]==')' && s.top()=='(') s.pop();
	else if(s.empty()!=1 && str[i]==']' && s.top()=='[') s.pop();
	else f=1;
		    } 
    }

    if(f==0 && s.empty()==1) cout<<"yes"<<endl;
    else  cout<<"no"<<endl;
    while(s.empty()!=1)s.pop();
  }
  return 0;
}