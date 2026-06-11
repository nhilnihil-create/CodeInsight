#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
using Graph = vector<vector<int>>;

typedef long long ll;
typedef vector<int> vi;

const double PI=acos(-1.0);

int N,x,y;
void input()
{
    cin>>N>>x>>y;
}

void solve()
{
    Graph G(N+1);
    for (int i=1;i<N;++i) {
        G[i].push_back(i+1);
        G[i+1].push_back(i);
    }
    G[x].push_back(y);
    G[y].push_back(x);
    vi d; queue<int> q;
    map<int,int> M;
    for(int i=1;i<=N;++i){
        d.assign(N+1,-1);
        d[i]=0;
        q.push(i);
        while(!q.empty()){
            int v=q.front(); q.pop();
            for(auto nv:G[v]){
                if(d[nv]!=-1) continue;
                d[nv]=d[v]+1;
                M[d[nv]]++;
                q.push(nv);
            }
        }
    }
    for(int k=1;k<N;++k){
        cout<<M[k]/2<<"\n";
    }
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}