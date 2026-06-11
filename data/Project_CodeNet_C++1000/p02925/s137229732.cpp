#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> topo_sort(vector< vector<int> > &g) {
    int64_t n = g.size();
    vector<int> in(n);
    for(int v=0; v<n; v++) {
        for(auto u: g[v]) {
            ++in[u];
        }
    }
    queue<int> q;
    for(int i=0; i<n; i++) {
        if(in[i] == 0) q.emplace(i);
    }

    vector<int> res;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        res.emplace_back(v);
        for(auto u: g[v]) {
            if(--in[u] == 0) q.emplace(u);
        }
    }

    if(res.size() == n) {
        return res;
    } else {
        res.clear();
        return res;
    }
}

int main(void) {
    int N;
    cin >> N;

    vector< vector< int> > g(N*N);
    auto id = [N](int i, int j) {
        return i*N + j;
    };

    for(int i=0; i<N; i++) {
        vector<int> A(N-1);
        for(int j=0; j<N-1; j++) {
            cin >> A[j];
            --A[j];
        }
        for(int j=0; j<N-2; j++) {
            g[id(i, A[j])].emplace_back(id(i, A[j+1]));
            g[id(i, A[j])].emplace_back(id(A[j+1], i));
            g[id(A[j], i)].emplace_back(id(i, A[j+1]));
            g[id(A[j], i)].emplace_back(id(A[j+1], i));
        }
    }


    if(topo_sort(g).empty()) {
        cout << -1 << endl;
    } else {
        vector<int> dp(N*N, 1);
        for(auto v: topo_sort(g)) {
            for(auto u: g[v]) {
                dp[u] = max(dp[u], dp[v] + 1);
            }
        }
        cout << *max_element(dp.begin(), dp.end()) << endl;
    }
    return 0;
}
