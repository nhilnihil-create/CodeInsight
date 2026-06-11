#include <iostream>
#include <string>
#include <stack>
using namespace std;
string s;
bool solve() {
  stack<char> stk;
  for(int i=0; i!=(int)s.length(); ++i) {
    if(s[i] == '[' || s[i] == '(') stk.push(s[i]);

    else if(s[i] == ']') {
      if(stk.empty()) return 0;
      if(stk.top() != '[') return 0;
      stk.pop();
    }
    else if(s[i] == ')') {
      if(stk.empty()) return 0;
      if(stk.top() != '(') return 0;
      stk.pop();
    }
  }
  return stk.empty();
}

int main() {
  while(getline(cin, s) && s != ".") {
    cout << (solve() ? "yes" : "no") << endl;
  }
  return 0;
}
