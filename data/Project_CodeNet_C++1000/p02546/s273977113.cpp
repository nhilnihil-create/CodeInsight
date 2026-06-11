#include<bits/stdc++.h>
using namespace std;
int main()
{
    char m[1005];
    scanf(" %[^\n]",m);
    int l;
    l=strlen(m);
    if(m[l-1]=='s')
    {
        printf("%ses\n",m);
    }
    else
    {
        printf("%ss\n",m);
    }
    return 0;


}
