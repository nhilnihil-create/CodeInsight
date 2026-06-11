#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int main ()
{
    char s[100];
    stack<int>A;
    int a,b;
    while(~scanf("%s",s))
    {
        if(s[0]=='+')
        {
            a=A.top();
            A.pop();
            b=A.top();
            A.pop();
            A.push(a+b);
        }
        else if(s[0]=='-')
        {
            a=A.top();
            A.pop();
            b=A.top();
            A.pop();
            A.push(b-a);
        }
        else if(s[0]=='*')
        {
            a=A.top();
            A.pop();
            b=A.top();
            A.pop();
            A.push(a*b);
        }
        else
        {
            A.push(atoi(s));
        }
    }
    printf("%d\n",A.top());
    return 0;
}

