#define inf 9223372036854775807
#define ll long long
#define pii pair<ll,ll>
#define m_p  make_pair
#define ull unsigned long long
#define spd  ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ll h,w,m,i,hi,wi,r,c,mxr=0,ans=0,mxc=0;

    cin>>h>>w>>m;

    map<ll,ll>row,col;
    map<ll,map<ll,ll>>mp;
    vector<ll>vr,vc;

    for(i=0;i<m;i++)
    {
        cin>>hi>>wi;
        mp[hi][wi] = 1;
        row[hi]++;
        col[wi]++;
    }

    for(i=1;i<=h;i++)
    {
        if(row[i]>mxr)
        {
            mxr = row[i];

            r = i;
        }
    }


    for(i=1;i<=w;i++)
    {
        if(col[i]>mxc)
        {
            mxc = col[i];
            c = i;
        }
    }

    for(i=1;i<=h;i++)
    {
        if(mxr==row[i])
        {
            vr.push_back(i);
        }
    }

    for(i=1;i<=w;i++)
    {
        if(mxc==col[i])
        {
            vc.push_back(i);
        }
    }

    for(i=0;i<vr.size();i++)
    {
        for(int j=0;j<vc.size();j++)
        {
            if(!mp[vr[i]][vc[j]])
            {
               cout<<mxr+mxc<<endl;
               return 0;
            }
        }
    }

    cout<<mxr+mxc-1<<endl;
}
