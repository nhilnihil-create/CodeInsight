#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int sz = 2e5+10;




 
 
int main()
{
    
    int t;
    t=1;
    // cin>>t;
    for(int cs=1;cs<=t;cs++)
    {
 
        ll n;
        cin>>n;
        ll dis[n],val[n],val2[n-1];
        for(int i=0;i<n;i++)
        {
            cin>>dis[i];
            dis[i]--;
        }
        for(int i=0;i<n;i++)
        {
            cin>>val[i];
        }
        for(int i=0;i<n-1;i++)
        {
            cin>>val2[i];
        }
        ll res = val[dis[0]];
        for(int i=1;i<n;i++)
        {
            res+=val[dis[i]];
            if(dis[i]-dis[i-1]==1)
            {
                res+=val2[dis[i-1]];
            }

        }
        cout<<res;


 
    }
    return 0;
} 