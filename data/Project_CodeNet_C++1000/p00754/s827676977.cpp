#include <iostream>
#include <stack>
using namespace std;

int main()
{
  string str;

  while (getline(cin,str))
  {
    if (str == ".") return 0;

    stack<char> p;
    bool flag = true;

    for (int i=0;i<str.length();i++)
    {
      if (str[i] == '(') p.push('(');
      else if (str[i] == ')')
      {
        if (!p.empty() && (p.top() != '(')) { flag = false; break; }
        if (p.empty()) { flag = false; break; }
        p.pop();
      }
      else if (str[i] == '[')  p.push('[');
      else if (str[i] == ']')
      {
        if (!p.empty() && (p.top() != '[')) { flag = false; break; }
        if (p.empty()) { flag = false; break; }
        p.pop();
      }
    }
    if (flag && p.empty()) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}