#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int h,w,m;cin>>h>>w>>m;
    map<int,int> mph,mpw;
    set<pair<int,int>> st;
    int maxh=0,maxw=0;
    for(int i=0;i<m;i++)
    {
        int y,x;cin>>y>>x;

        mph[y]++;
        mpw[x]++;
        maxh=max(maxh,mph[y]);
        maxw=max(maxw,mpw[x]);
        st.insert({y,x});
    }

    vector<int> vh,vw;

    for(auto mm:mph)
    {
        if(mm.se==maxh)vh.push_back(mm.fi);
    }

    for(auto mm:mpw)
    {
        if(mm.se==maxw)vw.push_back(mm.fi);
    }

    int ans=maxh+maxw-1;

    for(auto ih:vh)for(auto iw:vw)
    {
        if(st.find({ih,iw})==st.end())
        {
            ans++;
            cout<<ans<<"\n";
            return 0;
        }
    }

    cout<<ans<<"\n";

    return 0;
}
