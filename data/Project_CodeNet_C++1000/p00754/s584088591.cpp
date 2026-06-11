#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isParen(char c){
  return c == '(' || c == ')' || c == '[' || c == ']';
}
bool leftParen(char c){
  return c == '(' || c == '[';
}
bool rightParen(char c){
  return c == ')' || c == ']';
}
char matchParen(char c){
  if(c == '(')return ')';
  if(c == '[')return ']';
  return '_';
}
bool check(string& s){
  stack<char> stack;
  for(char c:s){
    if(leftParen(c)){
      stack.push(c);
    }else if(rightParen(c)){
      if(stack.empty())return false;
      if(c != matchParen(stack.top()))return false;
      stack.pop();
    }
  }
  return stack.empty();
}
int main(){
  while(true){
    string s;
    getline(cin,s);
    if(s == ".")break;
    cout << (check(s) ? "yes" : "no") << endl;
  }
}