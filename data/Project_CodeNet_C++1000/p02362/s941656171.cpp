#include<bits/stdc++.h>
using namespace std;

#define INF 10000000

struct edge {int from,to,cost;};

edge es[2000];

int d[1000];
int v,e;

/*
bool find_negative_loop(){
    fill(d,d+1000,0);

    for(int i=0;i<v;i++){
        for(int j=0; j<e; j++){
            edge ed = es[j];
            if(d[ed.to] > d[ed.from] + ed.cost){
                d[ed.to] = d[ed.from] + ed.cost;

                if(i == v-1) return true;
            }
        }
    }
    return false;
}*/

bool shortest_path(int s){
    for(int i=0; i<v; i++){
        d[i] = INF;
    }
    d[s] = 0;
    int count = 0;
    while(1){
        if(count > v){
            return true;
        }
        bool update = false;
        for(int i=0; i<e; i++){
            edge ed = es[i];
            if(d[ed.from] != INF && d[ed.to] > d[ed.from] + ed.cost){
                d[ed.to] = d[ed.from] + ed.cost;
                update = true;
            }
        }
        if(!update) break;
        count++;
    }
    return false;
}

int main(){

    int r,s,t,dd;

    cin >> v >> e >> r;

    for(int i=0; i<e; i++){
        cin >> s >> t >> dd;
        es[i].to = t;
        es[i].from = s;
        es[i].cost = dd;
    }

    if(shortest_path(r)){
        cout << "NEGATIVE CYCLE" << endl;
    }
    else{
        for(int i=0;i<v;i++){
            if(d[i] == INF){
                cout << "INF" << endl;
            }
            else{
                cout << d[i] << endl;
            }
        }
    }

    return 0;
}