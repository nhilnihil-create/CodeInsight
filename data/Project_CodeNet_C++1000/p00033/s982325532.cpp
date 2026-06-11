#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int a[10];
int b[10];
bool flag;
int c[10];
void dfs(int aa,int bb,int cc)
{
    if(bb+cc==10)
    {
        flag=true;
        return ;
    }
    if(bb==0||(a[aa]>b[bb-1]&&b[bb]==0))
    {
        b[bb]=a[aa];
        dfs(aa+1,bb+1,cc);
        b[bb]=0;
    }
    if(cc==0||(a[aa]>c[cc-1]&&c[cc]==0))
    {
        c[cc]=a[aa];
        dfs(aa+1,bb,cc+1);
        c[cc]=0;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        for(int i=0;i<10;i++)
            cin>>a[i];
        flag=false;
        dfs(0,0,0);
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");


    }
    return 0;
}