#include<bits/stdc++.h>

using namespace std;
#define ll long long
int main()
{
    ll h,w,st[102][102],nb=0,x[]={1,0},y[]={0,1};
    char grid[102][102];
    cin>>h>>w;
    for(ll i=0;i<h;i++)
    {
        for(ll j=0;j<w;j++)
        {
            cin>>grid[i][j];
            st[i][j]= -1;
        }
    }
    queue<pair<ll,ll> > que;
    que.push({0,0});
    if(grid[0][0]=='#')st[0][0]=1;
    else st[0][0]=0;
    while(!que.empty())
    {
        ll nx=que.front().first,ny=que.front().second;
        que.pop();
        for(ll i=0;i<2;i++)
        {
            ll cx=nx+x[i],cy=ny+y[i],cs;
            if(cx>=h || cy>=w)continue;
            if(grid[cx][cy]=='#' && grid[nx][ny]!='#')cs=st[nx][ny]+1;
            else cs=st[nx][ny];
            if(st[cx][cy]==-1 || cs<st[cx][cy]){que.push({cx,cy});st[cx][cy]=cs;}
        }
    }
    cout<<st[h-1][w-1]<<endl;

    return 0;
}
