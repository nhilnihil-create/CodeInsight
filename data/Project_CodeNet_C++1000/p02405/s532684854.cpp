#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j,k;
    while(scanf("%d %d",&n,&m)!=0)
    {
        if(n==0&&m==0)
            break;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(i%2==0)
                {
                    if(j%2!=0)
                        printf(".");
                    else printf("#");
                }
                else
                    {
                    if(j%2!=0)
                        printf("#");
                    else printf(".");
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}

