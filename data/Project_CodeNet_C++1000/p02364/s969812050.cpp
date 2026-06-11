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
typedef pair<ll,pair<int,int> > P;
typedef unsigned long long int ull;
const ll MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e9;

int V,E;
struct edge{
    int to,cost;
};

vector<vector<edge> > G(MAXV);
vector<bool> used(MAXV,false);

int prim(){
    priority_queue<ii,vector<ii>,greater<ii> > que;
    que.push(ii(0,0));
    int res=0;
    while(!que.empty()){
        int cst=que.top().first;
        int v=que.top().second;
        que.pop();
        if(used[v]) continue;
        used[v]=true;
        res+=cst;
        for(int i=0;i<(int)G[v].size();i++){
            edge e=G[v][i];
            que.push(ii(e.cost,e.to));
        }
    }
    return res;
}

int main(){
    cin>>V>>E;
    for(int i=0;i<E;i++){
        int s,t,w;cin>>s>>t>>w;
        G[s].push_back(edge{t,w});
        G[t].push_back(edge{s,w});
    }
    int ans=prim();
    cout<<ans<<endl;
    return 0;
}
