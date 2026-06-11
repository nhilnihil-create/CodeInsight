#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1010000000000000017LL;
const ll MOD = 1000000007LL;

#define REP(i, n) for(ll i = 0 ; i < n; i++)

//#define DEBUG(fmt, ...)
#define DEBUG(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)

/*
void Method1(){
    ll V, E;

    cin >> V >> E;
    vector<vector<int>> graph(V);
    vector<int> incoming(V);

    REP(i, E){
        ll s, t;
        cin >> s >> t;
        graph[s].push_back(t);
        incoming[t]++;
    }

    queue<int> zero_queue;
    REP(i, V){
        if(incoming[i] == 0){
            zero_queue.push(i);
        }
    }

    while(!zero_queue.empty()){
        ll cur = zero_queue.front();
        zero_queue.pop();
        cout << cur << endl;
        REP(i, graph[cur].size()){
            incoming[graph[cur][i]]--;
            if(incoming[graph[cur][i]] == 0 ){
                zero_queue.push(graph[cur][i]);
            }
        }
    }

}
*/

bool DFS(vector<vector<int>>& graph, int v, vector<int>& visited, vector<int>& done, stack<int>& sorted){
    if( visited[v] ){
        return false;
    }
    if( done[v]) {
        return true;
    }

    visited[v] = true;
    REP(i, graph[v].size() ){
        if( !DFS(graph, graph[v][i], visited, done, sorted) ){
            return false;
        }
    }
    visited[v] = false;
    done[v] = true;
    sorted.push(v);

    return true;
}

int main(){
    std::cout<<std::fixed<<std::setprecision(10);

    ll V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V);
    vector<int> incoming(V);

    REP(i, E){
        ll s, t;
        cin >> s >> t;
        graph[s].push_back(t);
        incoming[t]++;
    }

    vector<int> visited(V, false);
    vector<int> done(V, false);
    stack<int> sorted;
    REP(i,V){
        if(!DFS(graph, i, visited, done, sorted) ){
            cout << "not DAG" << endl;
            return 0;
        }
    }

    while(!sorted.empty()){
        cout << sorted.top() << endl;
        sorted.pop();
    }
}

