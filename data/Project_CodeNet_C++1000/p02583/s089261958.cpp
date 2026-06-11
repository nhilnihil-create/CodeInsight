#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll a[n],i,j,k,x,y,z,cnt=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            for(k=j+1;k<n;k++)
            {
                x=a[i],y=a[j],z=a[k];
                if(x+y>z&&y+z>x&&x+z>y&&x!=y&&y!=z&&z!=x)
                    cnt++;
            }
        }
    }
    cout<<cnt;
}