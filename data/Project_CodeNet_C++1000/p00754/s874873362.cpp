#include <iostream>
#include <stack>
using namespace std;
void startstack(stack<int> &st){
  st.empty();
  st.push(0);
}
void clear(string &tmp){
  int j;
  do{
    for(j=0;tmp[j];j++);
    if(tmp[--j]=='.') break;
  }while(getline(cin,tmp));
}
int main(){
  int i,j;
  stack<int> st;
  string tmp;
  startstack(st);
  getline(cin,tmp);
  while(tmp!="."){
    for(i=0;tmp[i];i++){
      if(tmp[i]=='('||tmp[i]=='['){
	st.push(tmp[i]);
      }
      if(tmp[i]==']'){
	if(st.top()=='[') st.pop();
	else {startstack(st);
	  cout <<"no\n";
	  clear(tmp);
	  break;}
      }
      if(tmp[i]==')'){
	if(st.top()=='(') st.pop();
	else {startstack(st);
	  clear(tmp);
	  cout <<"no\n";
	  break;
	}
      }
      if(tmp[i]=='.'){
	if(st.top()==0) {cout <<"yes\n";
	  startstack(st);}
	else {
	  cout <<"no\n";
	  startstack(st);
	  break;}
      }
    }
    getline(cin,tmp);
  }
      return 0;
}