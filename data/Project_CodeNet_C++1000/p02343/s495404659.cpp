#include<cstdio>
#include<algorithm>
using namespace std;
int s[10001];
int finds(int n)
{
    if(s[n]==n)
        return n;
    else return s[n]=finds(s[n]);
}
int unionh(int a,int b)
{
    a=finds(a); b=finds(b);
    s[a]=b;
}

int main()
{
    for(int i=0; i<=10000; i++) s[i]=i;
    int n,q,op,x,y;
    scanf("%d%d",&n,&q);
    for(int i=0;i<q;i++)
    {
        scanf("%d%d%d",&op,&x,&y);
        if(op==0) unionh(x,y);
        else{
            if(finds(x)==finds(y)) printf("1\n");
            else printf("0\n");
        }
    }
}