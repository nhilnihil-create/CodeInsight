#include <iostream>
#include <stack>
using namespace std;

int main()
{
  string s;
  while(1){
    getline(cin,s);
    if(s == ".")
      break;
    stack<char> b;
    bool flag = true;
    for(int i = 0; i < s.size(); i++){
      if(s[i] == '('){
        b.push('(');
      }else if(s[i] == '['){
        b.push('[');
      }else if(s[i] == ')'){
        if(b.empty() || b.top() != '('){
          cout << "no" << endl;
          flag = false;
          break;
        }
        b.pop();
      }else if(s[i] == ']'){
        if(b.empty() || b.top() != '['){
          cout << "no" << endl;
          flag = false;
          break;
        }
        b.pop();
      }
    }
    if(b.empty() && flag)
      cout << "yes" << endl;
    else if(!b.empty() && (b.top() == '(' || b.top() == '[') && flag)
      cout << "no" << endl;
  }
}