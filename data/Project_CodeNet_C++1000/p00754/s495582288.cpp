#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
char s[200];
stack <char> ss;
int main()
{
    while (fgets(s,150,stdin))
    {
        int len=strlen(s);
        s[len-1]=0;
        if (strcmp(s,".")==0) break;
        len--;
        while (!ss.empty()) ss.pop();
        bool ok=true;
        for (int i=0;i<len;i++)
        {
            if (s[i]=='(') ss.push('(');
            else if (s[i]=='[') ss.push('[');
            else if (s[i]==')')
            {
                if (ss.empty()||ss.top()!='(')
                {
                    ok=false;
                    break;
                }
                ss.pop();
            }
            else if (s[i]==']')
            {
                if (ss.empty()||ss.top()!='[')
                {
                    ok=false;
                    break;
                }
                ss.pop();
            }
        }
        if (ok)
            if (!ss.empty()) ok=false;
        if (ok) puts("yes");
        else puts("no");
    }
    return 0;
}