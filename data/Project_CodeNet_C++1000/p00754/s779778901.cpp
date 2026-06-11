#include <iostream>
#include <stack>
using namespace std;

    stack<char> kakko;

int main() {
  string str;
  char x;
  while(getline(cin,str)) {
    if(str == ".") return 0;
    bool r = true;

    while(!kakko.empty()) {
      kakko.pop();
    }

    for(unsigned int i=0;i<str.size();i++) {
      x = *str.substr(i,1).c_str();
      if(x == '(' || x == '[') {
        kakko.push(x);
      }
      else if(x == ')') {
        if(!kakko.empty()) {
          if(kakko.top() == '(') {
            kakko.pop();
          }
          else {
            r = false;
          }
        }
        else {
          r = false;
        }
      }
      else if(x == ']') {
        if(!kakko.empty()) {
          if(kakko.top() == '[') {
            kakko.pop();
          }
          else {
            r = false;
          }
        }
        else {
          r = false;
        }
      }
    }
    if(r && kakko.empty()) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}