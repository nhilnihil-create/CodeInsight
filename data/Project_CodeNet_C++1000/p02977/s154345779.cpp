#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x)
{
    x=0;char c=getchar();bool flag=false;
    while(!isdigit(c)){if(c=='-')flag=true;c=getchar();}
    while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    if(flag)x=-x;
}
int n;
int main()
{
    read(n);
    if(n==(n&(-n)))
    {
        puts("No");
        return 0;
    }
    printf("Yes\n1 2\n2 3\n3 %d\n%d %d\n%d %d\n",n+1,n+1,n+2,n+2,n+3);
    for(int i=4;i+1<=n;i+=2) printf("1 %d\n1 %d\n%d %d\n%d %d\n",i,i+1,i,i+1+n,i+1,i+n);
    if(!(n&1))
    {
        for(int i=2;i<n;++i) 
        {
            if(i==3) continue;
            int p=n^i^1;
            if(p!=3&&p<n)
            {
                printf("%d %d\n%d %d\n",i,n,p,2*n);
                break;
            }
        }
    }
    return 0;
}