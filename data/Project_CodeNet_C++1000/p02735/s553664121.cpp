#include<bits/stdc++.h>
using namespace std;

#define mx 105
#define ll long long

int ar[mx][mx];
char ch[mx][mx];

int n,m,k,ii;

void solve()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",ch[i]+1);

    if(ch[1][1]=='#')ar[1][1]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1 && j==1)continue;

            if(i>1)
            {
                int val=0;
                if(ch[i-1][j]!=ch[i][j] && ch[i][j]=='#')val++;
                ar[i][j]=ar[i-1][j]+val;
            }
            else ar[i][j]=1000;

            if(j>1)
            {
                int val=0;
                if(ch[i][j-1]!=ch[i][j] && ch[i][j]=='#')val++;
                ar[i][j]=min(ar[i][j],ar[i][j-1]+val);
            }
        }
    }
    printf("%d\n",ar[n][m]);
}

int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int t=1;
  // scanf("%d",&t);
   while(t--)solve();
   return 0;
}
