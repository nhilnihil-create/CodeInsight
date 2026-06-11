#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<pair<int,int>>v[20];
int boom[20];
int main()
{
    int n;cin>>n;
    int a,b;
    for(int i=1;i<=n;i++)
    {
        int m;cin>>m;
        for(int j=0;j<m;j++)
        {
            cin>>a>>b;
            v[i].push_back({a,b});
        }
    }
    int ans=0;
    for(int i=1;i<1<<n;i++)
    {
        int t=i;
        int temp=1;
        int ok=1;
        memset(boom,-1,sizeof(boom));
        while(t)
        {
            if(t&1)
            {
                if(boom[temp]==0) ok=0;
                else boom[temp]=1;
                for(pair<int,int>a:v[temp])
                {
                    if(boom[a.first]!=-1&&boom[a.first]!=a.second)
                        ok=0;
                    else
                        boom[a.first]=a.second;
                }
            }
            else
            {
                if(boom[temp]==1) ok=0;
                else boom[temp]=0;
            }
            temp++;
            t/=2;
        }
        for(int j=temp;j<=n;j++)
        {
            if(boom[j]==1) ok=0;
        }
        t=i;
        //cout<<ok<<endl;
        if(ok)
        {
            int sum=0;
            for(;t;t/=2) if(t&1) sum++;
            ans=max(ans,sum);
        }
    }
    cout<<ans<<endl;
}
