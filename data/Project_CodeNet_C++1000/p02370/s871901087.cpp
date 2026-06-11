/*BFS 的做法 */
/*
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<list>
#define N 10002  //憨批
using namespace std;
vector<int> G[N+1];
list<int> ans;
bool visited[N+1];
int indeg[N+1];
int n;

void bfs(int node){
    queue<int> q;
    q.push(node);
    visited[node]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        ans.push_back(u);
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            indeg[v]--;
            if(indeg[v]==0 && visited[v]==false){ //这里缺少了一个条件
                q.push(v);
                visited[v]=true;
            }
        }
    }
}

void topologicalSort(){
    for(int i=0;i<n;i++){
        if(indeg[i]==0 && visited[i]==false){
            bfs(i);
        }
    }
    for(list<int>::iterator it=ans.begin();it!=ans.end();it++){
        cout<<*it<<endl;
    }
}


int main(){
    int q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        //G[i].clear();
        visited[i]=false;
        indeg[i]=0;
    }
    for(int i=0;i<q;i++){
        int s,t;
        cin>>s>>t;
        G[s].push_back(t);
        indeg[t]++;
    }

    topologicalSort();

    return 0;
}
*/


/* DFS 的做法 */
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<list>
#define N 10002  //憨批
using namespace std;
vector<int> G[N+1];
list<int> ans;
bool visited[N+1];
int indeg[N+1];
int n;

void dfs(int node){
    visited[node]=true;
    for(int i=0;i<G[node].size();i++){
        int v=G[node][i];
        if(visited[v]==false){
            //visited[v]=true;
            dfs(v);
        }
    }
    ans.push_front(node);
}

int main(){
    int q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        //G[i].clear();
        visited[i]=false;
        indeg[i]=0;
    }
    for(int i=0;i<q;i++){
        int s,t;
        cin>>s>>t;
        G[s].push_back(t);
        indeg[t]++;
    }

    for(int i=0;i<n;i++){
        if(visited[i]==false){
            dfs(i);
        }
    }
    for(list<int>::iterator it=ans.begin();it!=ans.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}

