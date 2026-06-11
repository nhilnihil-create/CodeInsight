#include<bits/stdc++.h>
using namespace std;
typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;
typedef vector< vector<char> > vvc;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef long long ll;

void bfs(const vvi &graph, vi &arrive, vi &ans, int start){
    queue<int> que;
    que.push(start);
    arrive[start]=0;
    while(!que.empty()){
        int v=que.front();
        que.pop();
        for(auto next : graph[v]){
            if(arrive[next]!=-1) continue;
            arrive[next]=arrive[v]+1;
            ans[arrive[next]]++;
            que.push(next);
        }
    }
    return;
}

int main(){
    int n,x,y;
    cin >> n >> x >> y;
    vvi graph(n+1);
    graph[1].push_back(2);
    for(int i=2;i<n;i++){
        graph[i].push_back(i+1);
        graph[i].push_back(i-1);
    }
    graph[n].push_back(n-1);
    graph[x].push_back(y);
    graph[y].push_back(x);
    vi ans(n);
    for(int i=1;i<=n;i++){
        vi arrive(n+1,-1);
        bfs(graph,arrive,ans,i);
    }
    for(int i=1;i<n;i++){
        cout << ans[i]/2 << endl;
    }
    return 0;
}