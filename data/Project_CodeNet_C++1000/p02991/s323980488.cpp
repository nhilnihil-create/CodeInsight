#include<bits/stdc++.h>
using namespace std;
#define ll long long


const int maxn=200005;

vector<int>E[maxn];
int n,m;
ll d[maxn][3]; //dis ij，代表到第i个点的距离%3=j

void init()
{
   for(int i=0;i<maxn;i++)
    E[i].clear();
    for(int i=1;i<maxn;i++)
        for(int j=0;j<3;j++)
        d[i][j]=-3;  //让-3/3=-1

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
        init();
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            E[x].push_back(y);
        }
        int s,t;
        cin>>s>>t;
       queue<pair<int,int>>q;
        d[s][0]=0;
        q.push({s,0});
        while(!q.empty())
        {
            int cx=q.front().first,cy=q.front().second,ny=(cy+1)%3;//+1是因为要到下一个点
            q.pop();
            for(int i=0;i<int(E[cx].size());i++)
            {
                int nx=E[cx][i];
                if(d[nx][ny]==-3)
                {
                    d[nx][ny]=d[cx][cy]+1;//在转回来cy就是ny
                    q.push({nx,ny});
                }
            }
        }
        if(d[t][0]==1e15)
            cout<<-1<<'\n';
        else
           {
              cout<<d[t][0]/3<<'\n';
           }

}
