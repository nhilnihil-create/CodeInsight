#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int d[10][30010];
int ans[1000];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;
    str s;cin>>s;
    for(int i=0;i<n;i++)for(int j=0;j<10;j++)d[j][i+1]=d[j][i]+(j==s[i]-'0'?1:0);

    for(int i=0;i<n-2;i++)for(int j=0;j<10;j++)
    {
        if(d[j][n]-d[j][i+1]==0)continue;

        int l=i,r=n+1;
        for(int m=l+(r-l)/2;m!=l;m=l+(r-l)/2)
        {
            if(d[j][m]-d[j][i+1]>=1)r=m;
            else l=m;
        }
        for(int k=0;k<10;k++)
        {
            if(d[k][n]-d[k][l+1]>0)
            {
                ans[(s[i]-'0')*100+j*10+k]=1;
            }
        }
    }

    int cnt=0;
    for(int i=0;i<1000;i++)if(ans[i])cnt++;

    cout<<cnt<<"\n";

    return 0;
}
