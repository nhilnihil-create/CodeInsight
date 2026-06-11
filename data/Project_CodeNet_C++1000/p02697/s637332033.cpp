#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
bool vis[N];
int main()
{
    scanf("%d%d",&n,&m);
    if(n&1)
    {
        for(int i=1,l=1,r=n;i<=m;i++)
        {
            printf("%d %d\n",l,r);
            l++;r--;
        }
    }
    else
    {
        int k=(n-1)/2;
        k=k/2+k%2;
        int l=1,r=n;
        while(k&&(m--))
        {
            printf("%d %d\n",l,r);
            l++;r--;
            k--;
        }
        r--;
        if(m<0) m=0;
        while(m--)
        {
            printf("%d %d\n",l,r);
            l++;r--;
        }
    }
}
