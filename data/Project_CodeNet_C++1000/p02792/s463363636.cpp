#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    ft
    long long t,i,j,n,m,l=0,r,c[10][10];
    string s;
    cin>>n;
    memset(c,0,sizeof(c));
    for(i=1;i<=n;i++)
    {
        s=to_string(i);
        if((i%10)!=0)
        {
            c[s[0]-48][i%10]++;
        }
    }
    for(i=1;i<=9;i++)
    {
        for(j=1;j<=9;j++)
        {
            l+=(c[i][j]*c[j][i]);
        }
    }
    cout<<l<<"\n";
    return 0;
}