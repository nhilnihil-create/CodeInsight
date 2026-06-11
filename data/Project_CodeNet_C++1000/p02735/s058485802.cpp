#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ii> P;
typedef unsigned long long int ull;
const int MOD=1e9+7;
int dy[]={1,0};
int dx[]={0,1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e18;

int h,w;
vector<vector<char> > G(100,vector<char>(100));
vector<vector<ll> > d(100,vector<ll>(100,INF));

ll dijkstra(){
    priority_queue<P,vector<P>,greater<P> > que;
    que.push(P(0,ii(0,0)));
    d[0][0]=1;
    while(!que.empty()){
        P p=que.top();que.pop();
        ll cst=p.first;
        int y=p.second.first;
        int x=p.second.second;
        if(d[y][x]<cst) continue;
        for(int i=0;i<2;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny>=0&&ny<h&&nx>=0&&nx<w&&d[ny][nx]>d[y][x]+(G[y][x]==G[ny][nx]?0:1)){
                d[ny][nx]=d[y][x]+(G[y][x]==G[ny][nx]?0:1);
                que.push(P(d[ny][nx],ii(ny,nx)));
            }
        }
    }
    return d[h-1][w-1];
}
int main(){
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>G[i][j];
        }
    }
    ll ans=dijkstra()/2+((G[0][0]=='#'&&G[h-1][w-1]=='#')?1:0);
    cout<<ans<<endl;
    return 0;
}