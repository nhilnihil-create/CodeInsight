#include <iostream>
#include <stack>
using namespace std;

bool issame(char a,char b){
     if(a=='(')return b==')';
     if(a=='[')return b==']';
}

int main(){
     while(1){
	  string str;
	  getline(cin,str);
	  if(str[0]=='.')return 0;
	  char in;
	  stack<char> sta;
	  bool iscorrect=true;
	  int count=0;
	  while(in=str[count],in!='.'){
	       //cout<<in;
	       if(in=='('||in=='['){
		    sta.push(in);
		    //cout<<in<<endl;
	       }else if(in==')'||in==']'){
		    if(sta.empty()){
			 iscorrect=false;
			 break;
		    }
		    if(!issame(sta.top(),in)){
			 iscorrect=false;
			 break;
		    }
		    sta.pop();
	       }
	       count++;
	  }
	  cout<<((iscorrect&&sta.empty())? "yes":"no")<<endl;
     }
}