#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

bool judge(string &str) {
  stack<char> s;
  char c;
  for(int i = 0; i < str.size(); ++i) {
    if(str[i] == '(' || str[i] == '[') {
      s.push(str[i]);
    } else if(str[i] == ')') {
      if(s.empty()) return false;
      c = s.top();
      s.pop();
      if(c != '(') return false;
    } else if(str[i] == ']') {
      if(s.empty()) return false;
      c = s.top();
      s.pop();
      if(c != '[') return false;
    }
  }
  return s.empty();
}

int main() {
  string str;
  while(getline(cin, str) && str != ".") {
    if(judge(str)) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  return 0;
}