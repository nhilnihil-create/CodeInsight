#include <bits/stdc++.h>

typedef  long long ll;
typedef long double ld;
using namespace std;
const int N=1e5+5;

#define endl "\n"
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define point complex<double>
ll mod=1e9+7;
ll inf=2e18;
double eps=1e-10;
double pi=acos(-1);
double dot(point a, point b)
{
    return (conj(a)*b).real();
}
double cross(point a, point b)
{
    return (conj(a)*b).imag();
}
ll add(ll x, ll y)
{
    return (x%mod+y%mod)%mod;
}
point takepoint()
{
    int x, y;
    cin>>x>>y;
    point p(x,y);
    return p;
}
vector<int>v[N];
int dis [3][N];
void dig(int start)
{
    memset(dis,-1,sizeof dis);
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
    dis[0][start]=0;
    q.push({0,{0,start}});
    while(q.size())
    {
        int cu=q.top().first;
        int co=q.top().second.first+1;
        int node=q.top().second.second;
        q.pop();
        if(co==3)
            co=0,cu++;

        for(auto it:v[node])
        {
            if(dis[co][it]==-1||dis[co][it]>cu)
            {
                dis[co][it]=cu;
                q.push({cu,{co,it}});
            }

        }
    }


}

int main()
{
    int n,m;
    cin>>n>>m;
for(int i=0;i<m;i++)
{
    int u,x;
    cin>>u>>x;
    v[u].push_back(x);
}
int s,e;
cin>>s>>e;
dig(s);

cout<<dis[0][e];

    return 0;
}
