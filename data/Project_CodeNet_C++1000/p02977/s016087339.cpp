#include <bits/stdc++.h>
using namespace std;
#define Maxn 200007
int n;
void print(int x,int y)
{
    printf("%d %d\n",x,y);
}
int main()
{
    scanf("%d",&n);
    int tmp=n;
    while (tmp%2==0) tmp/=2;
    if (tmp==1)
    {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    print(1,2);
    print(2,3);
    print(3,n+1);
    print(n+1,n+2);
    print(n+2,n+3);
    for (int i=4;i<n;i+=2)
    {
        print(i,i+1);
        print(i+1,n+2);
        print(n+3,n+i);
        print(n+i,n+i+1);
    }
    if (n%2==0)
    {
        print(n-1,n);
        int r=(n-1)^n;
        if (r==3) print(n+1,n+n);
        else
        {
            r^=1;
            print(n+r,n+n);
        }
    }
    return 0;
}