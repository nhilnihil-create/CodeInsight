#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void){
  while(true){
    string s;
    getline(cin, s);
    if(s == "."){ break; }

    bool ans = true;
    stack<char> scale;
    for(size_t i = 0; ans && i < s.length(); i++){
      if(s[i] == '(' || s[i] == '['){ scale.push(s[i]); }
      else if(s[i] == ')' || s[i] == ']'){
        if(scale.empty()){ ans = false; }
        else if((s[i] == ')' && scale.top() == '(') || (s[i] == ']' && scale.top() == '[')){ scale.pop(); }
        else{ ans = false; }
      }
    }
    if(ans){ ans = scale.empty(); }

    if(ans){ cout << "yes" << endl; }
    else{ cout << "no" << endl; }
  }
  
  return 0;
}