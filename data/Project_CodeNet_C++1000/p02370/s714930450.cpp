#include<iostream>
#include<cstdio>
#include<vector>
#include<list>
#include<algorithm>
#define MAX 100000
using namespace std;

vector<int> G[MAX];
list<int> ans;
bool color[MAX];
int v, e;

void dfs(int u){
    color[u] = true;
    for(int i = 0; i < G[u].size(); i++){
        int x = G[u][i];
        if(!color[x]) dfs(x);
    }
    ans.push_front(u);
}

void tSort(){
    for(int i = 0; i < v; i++){
        if(!color[i]) dfs(i);
    }
}

int main(){
    int s, t;
    scanf("%d %d", &v, &e);
    for( int i = 0; i < v; i++) color[i] = false;
    for(int i = 0; i < e; i++){
        scanf("%d %d", &s, &t);
        G[s].push_back(t);
    }
    
    tSort();
    std::list<int>::iterator itr;
    for( itr = ans.begin(); itr != ans.end(); itr++){
        cout << *itr << endl;
    }
    return 0;
}
