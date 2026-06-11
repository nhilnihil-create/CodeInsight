#include <bits/stdc++.h>
using namespace std;

vector<int> b[3];

int ret10(int r)
{
    int ret=1;
    for(int i=0;i<r;i++)ret*=10;
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m;cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int s,c;cin>>s>>c;
        b[s-1].push_back(c);
    }

    for(int i=0;i<n;i++)b[i].erase(unique(b[i].begin(),b[i].end()),b[i].end());

    int ans=0;

    if(b[0].size()>1){cout<<-1<<"\n";return 0;}
    else if(b[0].size()==1)
    {
        if(b[0][0]==0&&n>1){cout<<-1<<"\n";return 0;}
        ans+=b[0][0]*ret10(n-1);
    }
    else 
    {
        if(n>1) ans+=ret10(n-1);
    }

    for(int i=1;i<n;i++)
    {
        if(b[i].size()>1){ans=-1;break;}
        if(b[i].size()==1)ans+=b[i][0]*ret10(n-i-1);
    }

    cout<<ans<<"\n";

    return 0;
}
