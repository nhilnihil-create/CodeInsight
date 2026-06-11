#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli a[3][3],i,j,k,x,n;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }
    cin>>n;
    while(n--)
    {
        cin>>x;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(a[i][j]==x)
                  a[i][j]=-1;
            }
        }
    }
    int cnt=0;
    int f=0;
    for(i=0;i<3;i++)
    {
        cnt=0;
        for(j=0;j<3;j++)
        {
            if(a[i][j]==-1)
             cnt++;
        }
        if(cnt==3)
        {
            f=1;
            break;
        }
    }
    int v1=0;
    for(i=0;i<3;i++)
    {
        v1=0;
        for(j=0;j<3;j++)
        {
            if(a[j][i]==-1)
               v1++;
        }
        if(v1==3)
        {
            f=1;
            break;
        }
    }
    if((a[0][0]==-1 && a[1][1]==-1 && a[2][2]==-1)||(a[0][2]==-1 && a[1][1]==-1 && a[2][0]==-1))
      cout<<"Yes"<<"\n";
    else if(f==1)
     cout<<"Yes"<<"\n";
    else
     cout<<"No"<<"\n";
}