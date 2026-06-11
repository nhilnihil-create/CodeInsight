#include <iostream>
#include <stack>
using namespace std;

bool issame(char a,char b){
     if(a=='(')return b==')';
     if(a=='[')return b==']';
}

int main(){
     while(1){
	  char in;
	  in=cin.peek();
	  //cout<<in;
	  if(in=='.')return 0;
	  stack<char> sta;
	  bool iscorrect=true;
 
	  while(cin.get(in),in!='.'){
	       if(cin.eof())return 0;
	       if(in=='('||in=='['){
		    sta.push(in);
	       }else if(in==')'||in==']'){
		    if(sta.empty()||!issame(sta.top(),in)){
			 iscorrect=false;
			 break;
		    }
		    sta.pop();
	       }
	  }
	  cout<<((iscorrect&&sta.empty())? "yes":"no")<<endl;
	  cin.ignore(100,'\n');
     }
}