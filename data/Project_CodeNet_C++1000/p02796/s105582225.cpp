#include<bits/stdc++.h>

using namespace std;

pair<int,int>a[100010];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[i]=make_pair(x+y,x-y);
    }
    sort(a+1,a+n+1);
    int nowr=-0x7f7f7f7f,ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i].second<nowr) continue;
        nowr=a[i].first;
        ans++;
    }
    cout<<ans<<'\n';
}