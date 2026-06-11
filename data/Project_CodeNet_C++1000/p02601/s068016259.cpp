#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int a,b,c,n;
int cmd(int q,int p)
{
    int i;
    if(q>p)
        return q;
    for(i=1;i<=n;i++)
    {
        q=q*2;
        if(q>p)
            break;
    }
    n=n-i;
    return q;
}
int main()
{

    scanf("%d %d %d %d",&a,&b,&c,&n);
    int t=a/b+1;
    int f=n-t;
    b=cmd(b,a);
    c=cmd(c,b);
    if(b>a&&c>b)
       cout<<"Yes"<<endl;
    else cout <<"No"<<endl;
    return 0;
}
