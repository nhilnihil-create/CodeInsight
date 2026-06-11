#include <bits/stdc++.h>
using namespace std;
int n;
#define Maxn 100007
int a[Maxn];
map<int,int> mp;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    if (n%3==0)
    {
        for (int i=1;i<=n;i++)
            ++mp[a[i]];
        int tmp=0;
        bool check=true;
        for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
            if ((*it).second%(n/3)!=0) check=false; 
            else if ((*it).second!=(n/3)*2) tmp^=(*it).first;
        if (check&&tmp==0) printf("Yes\n"); else printf("No\n");
    } else
    {
        bool flag=true;
        for (int i=2;i<=n;i++)
            if (a[i]!=a[1]) flag=false;
        if (flag&&a[1]==0) printf("Yes\n"); else printf("No\n");
    }
    return 0;
}