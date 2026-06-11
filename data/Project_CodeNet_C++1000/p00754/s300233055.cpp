#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
  stack<int> p;
  string str;
  bool a;
  while(1){
    getline(cin,str);
    a = true;
    if(str == ".") break;
    for(int i=0;i<str.length();i++){
      char ch = str[i];
      if(ch == '(') p.push(1);
      if(ch == '[') p.push(2);
      if(ch == ')'){
        if(p.empty()){
          a = false;
          break;
        }
        if(p.top() == 1){
          p.pop();
        } else{
          a = false;
          break;
        }
      }
      if(ch == ']'){
        if(p.empty()){
          a = false;
          break;
        }
        if(p.top() == 2){
          p.pop();
        }else{
          a = false;
          break;
        }
      }
    }
    if(!p.empty()) a = false;
    cout << (a?"yes":"no");
    while(!p.empty()){
      p.pop();
    }
    cout << endl;
  }
  return 0;
}

