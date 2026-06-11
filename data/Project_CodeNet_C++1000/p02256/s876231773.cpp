#include<cstdio>

int gcd(int x,int y)
{
    if(x%y!=0&&y!=0) gcd(y,x%y);
    else return y;
}

int main()
{
    int a,b;
    while(~scanf("%d%d",&a,&b)) printf("%d\n",gcd(a,b));
    return 0;
}