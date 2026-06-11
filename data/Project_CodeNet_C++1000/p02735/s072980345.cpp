#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000009
main()
{
    int h,w,i,j;
    cin>>h>>w;
    char s[h+1][w+5];
    for(i=0;i<h;i++)
    {
        cin>>s[i];
    }
    int ans[h][w];
    memset(ans,0,sizeof(ans));
    if(s[0][0]=='#')ans[0][0]++;
    int a=1,b=1;
    while(a<h || b<w)
    {
        if(a<h)
        {
            for(i=0;i<=b-1;i++)
            {
                if(i==0)
                {
                    ans[a][i]=ans[a-1][i];
                    if(s[a][i]=='#' && s[a-1][i]=='.')ans[a][i]++;
                }
                else
                {
                    int u,v;
                    u=ans[a-1][i];
                    if(s[a][i]=='#' && s[a-1][i]=='.')u++;
                    v=ans[a][i-1];
                    if(s[a][i]=='#' && s[a][i-1]=='.')v++;
                    ans[a][i]=min(u,v);
                }
            }
        }
        if(b<w)
        {
            for(i=0;i<=b-1;i++)
            {
                if(i==0)
                {
                    ans[i][b]=ans[i][b-1];
                    if(s[i][b]=='#' && s[i][b-1]=='.')ans[i][b]++;
                }
                else
                {
                    int u,v;
                    u=ans[i-1][b];
                    if(s[i][b]=='#' && s[i-1][b]=='.')u++;
                    v=ans[i][b-1];
                    if(s[i][b]=='#' && s[i][b-1]=='.')v++;
                    ans[i][b]=min(u,v);
                }
            }
        }
        if(a<h && b<w)
        {
            int u,v;
            u=ans[a-1][b];v=ans[a][b-1];
            if(s[a][b]=='#' && s[a-1][b]=='.')u++;
            if(s[a][b]=='#' && s[a][b-1]=='.')v++;
            ans[a][b]=min(u,v);
        }
        if(a<h)a++;
        if(b<w)b++;
    }
    /*for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }*/
    printf("%d\n",ans[h-1][w-1]);
}
