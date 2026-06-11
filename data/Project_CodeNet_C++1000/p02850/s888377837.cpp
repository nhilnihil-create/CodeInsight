#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int from;
    int to;
    int color;
};

struct Vertex {
    int id;
    bool visited;
    vector<Edge*> next;
};
void dfs(int pos, vector<Vertex>& v, int from = -1);
int main(void) {
    // グラフは木

    int64_t N,a,b;
    cin >> N;
    
    vector<Edge> e(N-1);
    vector<Vertex> v(N);

    for(int i=0;i<(N-1);i++) {
        cin >> a >> b;
        --a;--b;
        
        e[i].from= a;
        e[i].to = b;
        e[i].color = -1;
        v[a].id = a;
        v[b].id = b;
        v[a].visited = false;
        v[b].visited = false;
        v[a].next.push_back(&e[i]);
        v[b].next.push_back(&e[i]);
    }
    
    int maxsum = 0;
    for(auto it:v) {
        if(maxsum < it.next.size()) {
            maxsum = it.next.size();
        }
    }

    dfs(0,v);
    cout << maxsum << "\n";
    for(auto it:e) {
        cout << it.color << "\n";
    }
        
    return 0;
}

void dfs(int pos, vector<Vertex>& v, int from)  {
    if(v[pos].visited) return;

    v[pos].visited = true;
    
    unordered_set<int> colorset;
    for(int i = 0;i <v[pos].next.size();i++) {
        if(v[pos].next[i]->color != -1) {
            colorset.insert(v[pos].next[i]->color);
        }
    }
    if(colorset.size() == v[pos].next.size()) {
        return ;
    }
    
    int k = 1;
    for(int i = 0;i <v[pos].next.size();i++) {
        while(colorset.find(k) != colorset.end()) {
//printf("pos:%d, from:%d, k:%d, to:\n",pos,from,k, v[pos].next[i]->to);
            k++;
        }
        if(v[pos].next[i]->to == from) continue;
        if(v[pos].next[i]->color != -1) continue;
        v[pos].next[i]->color = k;
        colorset.insert(k);
        dfs(v[pos].next[i]->to, v, pos);
    }
}
