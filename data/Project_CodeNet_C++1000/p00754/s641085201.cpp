#include<iostream>
#include<stack>
#include<string>
using namespace std;

string str;

bool is_balance(){

  stack<char> s;

  for(int i=0 ; str[i] != '.' ; i++){
    if(str[i] == '(' || str[i] == '['){
      s.push(str[i]);
    }else if(str[i] == ')'){
      if(s.empty() || s.top() != '('){
	return false;
      }
      s.pop();
    }else if(str[i] == ']'){
      if(s.empty() || s.top() != '['){
	return false;
      }
      s.pop();
    }
  }

  if(s.empty()){
    return true;
  }

  return false;
  
}
int main(){

  while(1){

    getline(cin,str);

    if(str == ".")break;
    
    if(is_balance()){
      cout <<"yes"<<endl;
    }else{
      cout <<"no"<<endl;
    }
    
  }


  return 0;
}