#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class edge{
public:
    int from,to,num,p_color;
    edge(int _from, int _to, int _num):from(_from),to(_to),num(_num),p_color(-1){}
};

int main(){
    int n;
    cin>>n;
    vector<vector<edge>> G(n);
    for(int i=0;i<n-1;++i){
        int a,b;
        cin>>a>>b;
        --a,--b;
        G[a].emplace_back(a,b,i);
        G[b].emplace_back(b,a,i);
    }

    int max_color=0;
    for(int i=0;i<n;++i) max_color=max(max_color,(int)G[i].size());

    vector<int> res(n-1,-1);
    int color=0;
    queue<edge> que;
    for(auto e: G[0]) que.push(e);
    
    while (!que.empty())
    {
        edge e=que.front();
        que.pop();
        if(res[e.num]!=-1) continue;
        res[e.num]=color++%max_color+1;
        while(res[e.num]==e.p_color) res[e.num]=color++%max_color+1;
        for(auto nv :G[e.to]){
            nv.p_color=res[e.num];
            que.push(nv);
        }
    }
    
    cout<<max_color<<endl;
    for(int i=0;i<n-1;++i) cout<<res[i]<<endl;
}