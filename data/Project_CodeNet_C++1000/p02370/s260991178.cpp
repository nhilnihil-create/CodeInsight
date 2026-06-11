#include<map>
#include<vector>
#include<queue>
#include<cstdio>
#include<iostream>
using namespace std;

typedef pair<int,int> P;

vector<int> G[10000];

int main(void) {
    int v,e;
    scanf("%d%d",&v,&e);

    vector<int> res;
    vector<int> in(v);

    for(int i=0; i<e; i++) {
        int s,t;
        scanf("%d%d",&s,&t);
        G[s].push_back(t);
        in[t]++;
    }
    
    queue<int> q;
    for(int i=0; i<v; i++)
        if(in[i] == 0)
            q.push(i);
    while(q.size()) {
        int i = q.front(); q.pop();
        res.push_back(i);
        for(auto &j : G[i])
            if(--in[j] == 0)
                q.push(j);
    }
    for(auto &r : res)
        cout << r << endl;

    return 0;
}