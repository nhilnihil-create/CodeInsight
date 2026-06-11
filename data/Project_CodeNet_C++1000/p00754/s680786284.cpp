#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

main(){
  char c;
  while(scanf("%c", &c) != EOF){
    if(c == '.') break;
    stack<char> data;
    bool f = true;
    while(c != '\n'){
      if(f){
        if(c == '(' || c == '[') data.push(c);
        if(c == ')'){
          if(data.size() == 0 || data.top() != '(') f = false;
          else data.pop();
        }
        if(c == ']'){
          if(data.size() == 0 || data.top() != '[') f = false;
          else data.pop();
        }
      }
      scanf("%c", &c);
    }
    cout << (data.size() == 0 && f ? "yes" : "no") << endl;
  }
}