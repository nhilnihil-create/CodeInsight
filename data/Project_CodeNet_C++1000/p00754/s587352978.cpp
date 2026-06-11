#include<iostream>
#include<string>
#include<stack>
typedef unsigned int uint;
using namespace std;

inline bool opp(char c1,char c2){
  return (c1==')' && c2 == ']') || (c1==']' && c2==')');
}

bool check(string str){
  stack<uint> Stack;
  uint pos=0;
  for(;pos<str.size();pos++){
    if(str[pos]==')' || str[pos]==']') return false;
    if(str[pos]=='('){
      Stack.push(')');
      break;
    }else if(str[pos]=='['){
      Stack.push(']');
      break;
    }
  }
  
  for(pos++;pos<str.size();pos++){
    if(str[pos]=='('){
      Stack.push(')');
    }else if(str[pos]=='['){
      Stack.push(']');
    }
    else if(!Stack.empty()){
      char c=Stack.top();
      if(opp(str[pos],c)){
	return false;
      }else if(str[pos]==c){
	Stack.pop();
      }
    }else if(Stack.empty() && (str[pos]==')' ||str[pos]==']')){
      return false;
    }
  }
  if(Stack.empty())
    return true;  
  else 
    return false;
}

int main(){
  string str;
  while(getline(cin,str),str!="."){
    if(check(str))
      cout<<"yes"<<endl;
    else
      cout<<"no"<<endl;

  }
  return 0;
}