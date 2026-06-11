// verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A&lang=jp
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=jp

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class DAG {
public:
    DAG(const vector<vector<int>> &edges)
    : tsort_done(false), acyc(false) {
        V = edges.size();
        E.resize(V);
        for(int i = 0; i < V; ++i) {
            for(int to : edges[i]) {
                E[i].push_back(to);
            }
        }
    }

    bool tsort() {
        vector<int> indeg(V, 0);
        for(int i = 0; i < V; ++i) {
            for(int to : E[i]) ++indeg[to];
        }

        queue<int> done;
        for(int i = 0; i < V; ++i) {
            if(indeg[i] == 0) done.push(i);
        }

        while(!done.empty()) {
            int cur = done.front();
            done.pop();
            order.push_back(cur);
            for(int to : E[cur]) {
                --indeg[to];
                if(indeg[to] == 0) done.push(to);
            }
        }

        tsort_done = true;
        acyc = (order.size() == V);
        return acyc;
    }

    int longest_path() {
        if(!tsort_done) tsort();
        if(!acyc) return -1;

        dp.resize(V);
        for(int i = 0; i < V; ++i) {
            int cur = order[i];
            for(int to : E[cur]) {
                dp[to] = max(dp[to], dp[cur] + 1);
            }
        }

        return *max_element(begin(dp), end(dp));
    }

    bool acyclic() {
        if(!tsort_done) tsort();
        return acyc;
    }

    int operator[](int i) {
        if(!tsort_done) tsort();
        return order[i];
    }

private:
    int V;
    vector<vector<int>> E;
    vector<int> order;
    bool tsort_done;
    bool acyc;
    vector<int> dp;
};



#include <iostream>
int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edges(V);
    while(E--) {
        int s,t;
        cin >> s >> t;
        edges[s].push_back(t);
    }

    DAG dag(edges);
    dag.tsort();
    vector<int> res(V);
    for(int i=0; i<V; ++i) res[i] = dag[i];
    for(int i=0; i<V; ++i) {
        cout << res[i] << endl;
    }
}



// function only
bool tsort(vector<int> &order, const vector<vector<int>> &edges) {
    int V = edges.size();

    vector<int> indeg(V, 0);
    for(int i = 0; i < V; ++i) {
        for(int to : edges[i]) ++indeg[to];
    }

    queue<int> done;
    for(int i = 0; i < V; ++i) {
        if(indeg[i] == 0) done.push(i);
    }

    while(!done.empty()) {
        int cur = done.front();
        done.pop();
        order.push_back(cur);
        for(int to : edges[cur]) {
            --indeg[to];
            if(indeg[to] == 0) done.push(to);
        }
    }

    return order.size() == V;
}

