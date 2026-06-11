#include<bits/stdc++.h>
using namespace std;
long long INF = 1e18;

struct Edge{
    int from;
    int to;
    int cost;
};

int main(){
    int v,e,r;
    cin>>v>>e>>r;

    Edge g[e+100];
    long long d[v+100];

    for(int i=0; i<e; i++){
        cin>>g[i].from>>g[i].to>>g[i].cost;
    }
    for(int i=0; i<v; i++){
        d[i]=INF;
    }

    d[r] = 0;
    bool update = true;
    long long cnt = 0;

     while(update){
         
        update = false;

        for(int i = 0; i < e; i++){

            Edge e = g[i];
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){

                d[e.to] = d[e.from] + e.cost;

                update = true;

            }

        }

        if(!update) break;
         cnt++;
         if(cnt==v){
             cout<<"NEGATIVE CYCLE"<<endl;
             return 0;
         }

    }

    for(int i=0; i<v ;i++){
        if(d[i]==INF){
            cout<<"INF"<<endl;
        }else{
            cout<<d[i]<<endl;
        }
    }

    return 0;

}
