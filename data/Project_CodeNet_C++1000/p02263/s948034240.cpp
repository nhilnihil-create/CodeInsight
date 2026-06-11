#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

stack<int>s;
char ch[11];

int main()
{
    while(cin>>ch)
    {
        if(ch[0] != '+' && ch[0] != '-' && ch[0] != '*')
            s.push(atoi(ch));
        else if(ch[0] == '+')
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(a+b);
        }
        else if(ch[0] == '-')
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(b-a);
        }
        else if(ch[0] == '*')
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(a*b);
        }
    }
    cout << s.top() << endl;
    return 0;
}

