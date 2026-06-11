#include <iostream>
#include <stack>
using namespace std;
int main()
{
  for(;;){
    string s;
    getline(cin,s);
    if(s == ".") break;
    stack<char> q;
    bool balanced = true;
    for(int i=0; i<s.length(); i++){
      switch(s[i]){
      case '(':
      case '[':
        q.push(s[i]);
        break;
      case ')':
        if(q.empty() || q.top() != '('){
          balanced = false;
          break;
        }else{
          q.pop();
        }
        break;
      case ']':
        if(q.empty() || q.top() != '['){
          balanced = false;
          break;
        }else{
          q.pop();
        }
        break;
      }
    }
    if(balanced && q.empty()) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  return 0;
}