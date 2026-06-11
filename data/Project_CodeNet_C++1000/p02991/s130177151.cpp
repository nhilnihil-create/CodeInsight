#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

int S, T;
int N, M;

template<typename T>
void cout_vec(vector<T> &vec){
    for(int i=0; i<vec.size(); i++){
        if (i!=0){
            cout << ' ';
        }
        cout << vec[i];
    }
    cout << endl;
}

int dijkstra(int node, vector<vector<int> > &edge){
    vector<vector<int> > dist(N,vector<int>(3,MOD));

    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> que;
    que.push(make_tuple(0, node, 0));
    while((int)que.size()>0){
        int d=get<0>(que.top());
        int x=get<1>(que.top());
        int s=get<2>(que.top());
        que.pop();

        vector<int> tmp={d,x,s};
        //cout_vec(tmp);

        if(x==T && s==0){
            return d;
        }

        if(dist[x][s]<=d){
            continue;
        }else{
            dist[x][s]=d;
        }

        if(s==2){
            d++;
        }

        for(auto nx:edge[x]){
            que.push(make_tuple(d,nx,(s+1)%3));
        }
    }
    return -1;
}

int main(){
    cin >> N >> M;
    vector<vector<int> > edge(N,vector<int>(0));
    for(int i=0; i<M; i++){
        int u, v;
        cin >> u >> v;
        u--;v--;
        edge[u].push_back(v);
    }

    cin >> S >> T;
    S--;T--;
    cout << dijkstra(S, edge) << endl;
}