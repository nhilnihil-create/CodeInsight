#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool ok (string s)
{
    stack<char> stk;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]=='(') stk.push('(');
        if (s[i]=='[') stk.push('[');
        if (s[i]==')')
        {
            if (stk.empty()) return false;
            else if (stk.top()!='(') return false;
            else stk.pop();
        }
        if (s[i]==']')
        {
            if (stk.empty()) return false;
            else if (stk.top()!='[') return false;
            else stk.pop();
        }
    }
    if (stk.empty()) return true;
    else return false;
}

int main()
{
    vector<bool> f;
    string t;
    while (1)
    {
        getline(cin, t);
        if (t==".") break;
        f.push_back(ok(t));
    }
    for (int i=0; i<f.size(); i++) cout<<(f[i]? "yes\n" : "no\n");
    return 0;
}
