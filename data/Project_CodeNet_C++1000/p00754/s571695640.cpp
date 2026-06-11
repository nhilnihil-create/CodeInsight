#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;

int main(){
  int a;
  char c;
  bool f;
  stack<int> p;

  while(1){
    c = getchar();
    if(c == '.')break;
    f = true;
    while(!p.empty())p.pop();

    do{
      if(c == '(')p.push(1);
      if(c == '[')p.push(2);
      if(c == ')'){
	if(p.empty()){
	  f = false;
	}else{
	  a = p.top();
	  p.pop();
	  if(a!=1)f = false;
	}
      }
      if(c == ']'){
	if(p.empty()){
	  f = false;
	}else{
	  a = p.top();
	  p.pop();
	  if(a!=2)f = false;
	}
      }
      c = getchar(); 
    }while(c != '.');

    if(f && p.empty())cout << "yes" << endl;
    else cout << "no" << endl;

    getchar();
  }

}