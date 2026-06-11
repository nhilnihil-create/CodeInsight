#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
using namespace std;
typedef long long ll;
const double PI=acos(-1);
typedef pair<int,int>P;
const int mod =1e9+7;
const int di[]={-1,0,1,0};
const int dj[]={0,-1,0,1};

int main()
{
    int h,w;
    cin>>h>>w;
    vector<string> s(h);
    rep(i,h)
    {
        cin>>s[i];
    }
    vector<vector<int>> vl(h,vector<int>(w,0)),vr(h,vector<int>(w,0)),vu(h,vector<int>(w,0)),vd(h,vector<int>(w,0));
    int ans=0;
    rep(i,h)
    {
        int cl=0,cr=0;
        rep(j,w)
        {
            if(s[i][j]=='#')
            {
                cl=0;
            }
            else
            {
                cl++;
            }
            vl[i][j]=cl;

            if(s[i][w-j-1]=='#')
            {
                cr=0;
            }
            else
            {
                cr++;
            }
            vr[i][w-j-1]=cr;
        }
    }

    rep(i,w)
    {
        int cu=0,cd=0;
        rep(j,h)
        {
            if(s[j][i]=='#')
            {
                cu=0;
            }
            else
            {
                cu++;
            }
            vu[j][i]=cu;

            if(s[h-1-j][i]=='#')
            {
                cd=0;
            }
            else
            {
                cd++;
            }
            vd[h-1-j][i]=cd;
        }
    }
    rep(i,h)
    {
        rep(j,w)
        {
            ans=max(ans,vl[i][j]+vr[i][j]+vu[i][j]+vd[i][j]-3);
        }
    }
    cout<<ans;
}
