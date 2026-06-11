#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
char op[]="+-*/";
char item[105];
bool is_op(char c)
{
    for(int i=0;i<strlen(op);i++)
    {
        if(op[i]==c) return true;
    }
    return false;
}
int main()
{
//    freopen("in.txt","r",stdin);
    stack<int> ss;
    while(~scanf("%s",item))
    {
        if(strlen(item)==1)
        {
            if(!is_op(item[0]))   ss.push(atoi(item));
            else
            {
                int op2=ss.top();ss.pop();
                int op1=ss.top();ss.pop();
                switch(item[0])
                {
                case '+':
                    {
                        ss.push(op1+op2);
                        break;
                    }
                     case '-':
                    {
                        ss.push(op1-op2);
                        break;
                    }
                     case '*':
                    {
                        ss.push(op1*op2);
                        break;
                    }
                     case '/':
                    {
                        ss.push(op1/op2);
                        break;
                    }
                }
            }
        }
        else{
             ss.push(atoi(item));
        }
    }
    printf("%d\n",ss.top());
    return 0;
}