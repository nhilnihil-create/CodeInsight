#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e3+10;
int a[N],st[N],f[N][1<<13];
int main()
{
    int n,m,b;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i]>>b;
        int t,c=0;
        for(int j=1;j<=b;j++)
        {
            cin>>t;
            t--;
            c|=1<<t;
        }
        st[i]=c;
    }
    memset(f,0x3f,sizeof f);
    f[0][0]=0;
    for(int i=1;i<=m;i++)
    for(int j=0;j<=(1<<n)-1;j++)
    {
        f[i][j]=min(f[i][j],f[i-1][j]);
        f[i][j|st[i]]=min(f[i][j|st[i]],f[i-1][j]+a[i]);
    }
    if(f[m][(1<<n)-1]==0x3f3f3f3f)  cout<<-1;
    else    cout<<f[m][(1<<n)-1];
}