#include <iostream>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

vector<int> G[100000];
int V[100000];
list<int> ut;
int N;

void dfs(int u){
    V[u]=1;
    for(int i=0;i<G[u].size();i++){
        int v =G[u][i];
        if(!V[v])dfs(v);
    }
    ut.push_front(u);
}

int main(){
    int s,t,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        V[i]=0;
    }
    for(int i=0;i<M;i++){
        cin>>s>>t;
        G[s].push_back(t);
    }
    for(int i=0;i<N;i++){
        if(!V[i])dfs(i);
    }
    for(list<int>::iterator it =ut.begin();it !=ut.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}
