#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int to; //辺の行先
    int weight; //辺の重み
    int color; //辺の色
    Edge(int w,int t,int c):weight(w),to(t),color(c){}
};
using Graph=vector<vector<Edge>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(){
    int N;cin>>N;
    Graph G(N);
    rep(i,N-1){
        int from,to;
        cin>>from>>to;
        from--;to--;
        G[from].push_back(Edge(i,to,-1));
        G[to].push_back(Edge(i,from,-1));
    }
    //幅優先探索
    //スタートから何ステップで到達できるか
    vector<int>dist(N,-1);
    vector<int>colorlist(N);
    vector<int>ans(N-1);
    //発見済み訪問前の頂点を入れておく
    queue<int>que;
    int maxi=0;
    //初期条件
    dist[0]=0;
    que.push(0);
    colorlist.at(0)=0;
    //頂点0が初期ノード
    //BFS
    while(!que.empty()){
        int v=que.front(); que.pop();
        int cl=colorlist.at(v);
        int count=1;
        for(auto nv:G[v]){
            if(dist[nv.to]!=-1){
                continue;
            }//訪問済みなら無視
            dist[nv.to]=dist[v]+1;
            if(count==cl){
                count++;
            }
            nv.color=count;
            colorlist.at(nv.to)=count;
            ans.at(nv.weight)=count;
            que.push(nv.to);
            maxi=max(maxi,count);
            count++;
        }
    }
    cout<<maxi<<endl;
    rep(i,N-1){
        cout<<ans[i]<<endl;
    }
}
