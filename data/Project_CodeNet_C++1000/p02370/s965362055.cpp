#include<bits/stdc++.h>
using namespace std;
int n,e;
int color[10001];
int indegree[10001];
vector<int> ans;
vector<int> vec[10001];
void Topological(int s){
    queue<int> que;
    que.push(s);
    while(!que.empty()){
        int u=que.front();que.pop();
        ans.push_back(u);
        color[u]=1;
        for(int i=0;i<vec[u].size();++i){
            indegree[vec[u][i]]--;
            if(indegree[vec[u][i]]==0&&color[vec[u][i]]==0){
                que.push(vec[u][i]);
            }
        }
    }
}
int main(){
    scanf("%d %d",&n,&e);
    for(int i=0;i<e;++i){
        int u,v;
        scanf("%d %d",&u,&v);
        vec[u].push_back(v);
        indegree[v]++;
    }
    for(int i=0;i<n;++i){
        if(indegree[i]==0&&color[i]==0)
        Topological(i);
    }
    for(int i=0;i<n;++i){
        printf("%d\n",ans[i]);
    }
    return 0;
}

