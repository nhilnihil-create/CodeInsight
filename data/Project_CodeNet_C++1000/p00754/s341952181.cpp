#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
  string s;
  while(getline(cin, s) && s != ".") {
    stack<char> sta;
    bool b = true;
    for(int i = 0; i < s.size(); i++) {
      char c = s[i];
      if((c == ')' || c == ']') && sta.empty()) {
	b = false;
	break;
      }

      if(c == '(' || c == '[') {
	sta.push(c);
      }
      else if(c == ')' || c == ']') {
	if(c == ')' && sta.top() != '(') b = false;
	if(c == ']' && sta.top() != '[') b = false;
	sta.pop();
      }
    }
    if(b && sta.empty()) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}