#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

int main() {
  while(1){
    stack<char> s;
    string str;
    getline(cin, str);
    if (str == ".") break;
    bool valid = true;
    for(char c : str) {
      switch(c){
       case '(':
       case '[':
        s.push(c);
        break;
       case ')':
        if(s.empty() || s.top() != '('){
          valid = false;
        }else{
          s.pop();
        }
        break;
       case ']':
        if(s.empty() || s.top() != '['){
          valid = false;
        }else{
          s.pop();
        }
        break;
      }
    }
    if(valid && s.empty())
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
}