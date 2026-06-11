#include <iostream>
#include <stack>
using namespace std;

bool solve(string s)
{
    stack<char> bracket;

    for(int i=0; i < s.size(); i++)
    {
        switch(s[i])
        {
            case '(' :
            case '[' :
                bracket.push(s[i]);
                break;
            case ')' :
                if(bracket.empty() || bracket.top() != '(')
                {
                    return false;
                }
                bracket.pop();
                break;
            case ']' :
                if(bracket.empty() || bracket.top() != '[')
                {
                    return false;
                }
                bracket.pop();
                break;
            default :
                break;
        }
    } 
    
    return bracket.empty();
}

int main(void)
{
    for(;;)
    {
        string s;
        getline(cin, s);

        if (s == ".")
        {
            break;
        }
        else
        {
            cout << (solve(s) ? "yes" : "no") << endl;
        }
    }
    return 0;
}

