#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    char str[100];
    stack <int > S;
    
    while( scanf("%s", str)!= EOF )
    {
        if( isdigit ( str[0] ) )
            S.push( atoi(str) );
        else if ( str[0] == '+' )
        {
            int a=S.top();
            S.pop();
            int b=S.top();
            S.pop();
            S.push( a+b );
        }
        else if( str[0] == '-' )
        {
            int b=S.top();
            S.pop();
            int a=S.top();
            S.pop();
            S.push(a-b);
        }
        else if( str[0] == '*' )
        {
            int a=S.top();
            S.pop();
            int b=S.top();
            S.pop();
            S.push(a*b);
        }
    }
    cout << S.top() <<endl;
    return 0;
}