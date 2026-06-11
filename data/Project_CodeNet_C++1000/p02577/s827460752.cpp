#include <cstdio>
#include<iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char s[200005];
int main()
{
    scanf("%s",s);
    int len=strlen(s);
    int num=0;
    for(int i=0;i<len;i++)
    {
        num+=s[i]-'0';
    }
    if(num%9==0)
        puts("Yes");
    else
    {
        puts("No");
    }
    
    return 0;
}
