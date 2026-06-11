#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void){

  string s;
  stack <string> st;
  string::iterator it;
  
  while(getline(cin,s)){
    
    //cin>>s;
    it=s.end();
    it--;
    if(s.size()==1&&*it=='.')
      break;
  
    for(it=s.begin();it!=s.end();it++){

      if(*it=='('){
	st.push("(");
      }

      else if(*it=='['){
	st.push("[");
      }

      else if(*it==')'){
	if(st.empty())
	  st.push(")");
	
	if(st.top()=="(")
	  st.pop();
	else
	  st.push(")");
      }

      else if(*it==']'){
	if(st.empty())
	  st.push("]");
	
	if(st.top()=="[")
	  st.pop();
	else
	  st.push("]");
      }
    }

    if(st.empty())
      cout <<"yes"<<endl;

    else
      cout <<"no"<<endl;

    while(!st.empty()){
      st.pop();
    }
    
  }
  return 0;

}