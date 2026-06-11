#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    ft
    long long t,i,j,k,n,m,l=0,r,c[10][10];
    string s,p;
    cin>>n>>s;
    p="ABC";
    for(i=0;i+3<=n;i++)
    {
        r=0;
        for(j=i,k=0;k<3;j++,k++)
        {
            if(s[j]!=p[k])
            {
                r=1;
                break;
            }
        }
        l+=(r==0);
    }
    cout<<l<<"\n";
    return 0;
}

