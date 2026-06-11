#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool f(string &s) {
  vector<char> stack;
  for(int i=0; i<s.length(); ++i) {
    if(s[i] == '(') {
      stack.push_back('(');
    }
    if(s[i] == '[') {
      stack.push_back('[');
    }
    if(s[i] == ']') {
      if(stack.empty()) return false;
      if(stack.back() == '[') {
        stack.pop_back();
      }else{
        return false;
      }
    }
    if(s[i] == ')') {
      if(stack.empty()) return false;
      if(stack.back() == '(') {
        stack.pop_back();
      }else{
        return false;
      }
    }
  }
  if(stack.size() == 0) return true;
  return false;
}

int main() {
  string s;
  while(getline(cin,s)) {
    if(s == ".") break;
    cout<<(f(s)?"yes":"no")<<endl;
  }
}