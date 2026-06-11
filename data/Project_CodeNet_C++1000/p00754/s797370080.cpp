#include<iostream>
#include<stdio.h>
#include<string>
#include<stack>
using namespace std;
int brkat(string s){
  stack<int> st;
  int i;
  st.push(111);
  for(i=0;s[i]!=0;i++){
    if(s[i]=='[')       st.push(s[i]);	  
    if(s[i]=='(')       st.push(s[i]);
    if(s[i]==']')      
      {
      if('['!=st.top() )
	{  cout <<"no\n"; return 2;}
      st.pop();}	
  
    if(s[i]==')')  
      {
	if('('!=st.top() )
	  {cout <<"no\n"; return 2;}
	st.pop();}
    //    cout <<i<<"ggg\n";
  }
  if(st.top()!=111){
    cout <<"no\n"; return 2;}
  cout <<"yes\n"; return 0; 
  
}

int main(){
  stack<int> st;
  string s;
  //int ouput[10000];
  int i,j=0;

  while(1){
    i=0;
    getline(cin,s);
        if (s==".") break;
	  brkat(s);
    j++;
  }
  /*  for(i=0;i<j;i++){
    if (ouput[i]==2) cout <<"no\n";
    if (ouput[i]==0) cout <<"yes\n";
  }
  */
  return 0;
}