//RAVAN_2070
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fo(i,a,b) for(i=a;i<b;i++)
#define pb push_back
#define mp make_pair
void solve()
{
    int h,w,m,i,r,c;cin>>h>>w>>m;
    vector<int>R(h,0),C(w,0);
    map<pair<int,int>,int>M;
    fo(i,0,m)
    {
        cin>>r>>c;
        r--;c--;
        M[mp(r,c)]++;
        R[r]++;C[c]++;
    }
    int mxr,mxc;mxr=mxc=-1;
    fo(i,0,h)mxr=max(mxr,R[i]);
    fo(i,0,w)mxc=max(mxc,C[i]);

    vector<int>row,col;
    fo(i,0,h)if(R[i]==mxr)row.pb(i);
    fo(i,0,w)if(C[i]==mxc)col.pb(i);

    int ans=0;
    for(auto itr:row)
    {
        int f;
        for(auto itc:col)
        {
            f=1;
            int cnt=R[itr]+C[itc];
            if(M[mp(itr,itc)])f=0,cnt--;
            ans=max(ans,cnt);
            if(f==1)break;

        }
        if(f==1)break;
    }
    cout<<ans<<"\n";
    
}
int main()
{
    fastio
    solve();
    return 0;
}
