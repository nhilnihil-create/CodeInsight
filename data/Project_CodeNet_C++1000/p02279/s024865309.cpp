#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> e;
vector<int> pa;
vector<int> d;

void dfs(int id, int depth) {
    d[id] = depth;
    for ( int i = 0; i < e[id].size(); i++ ) {
        dfs(e[id][i], depth + 1);
    }
}

int main() {
    int N;
    cin >> N;
    e.resize(N, vector<int>());
    pa.resize(N, -1);
    d.resize(N, -1);
    int k,id,c;
    for ( int i = 0; i < N; i++ ) {
        cin >> id >> k;
        for ( int j = 0; j < k; j++ ) {
            cin >> c;
            e[id].push_back(c);
            pa[c] = id;
        }
    }
    for ( int i = 0; i < N; i++ ) {
        if ( pa[i] != -1 ) continue;
        dfs(i, 0);
    }
    int r = 0;
    while ( pa[r] != -1 ) r = pa[r];

    for ( int i = 0; i < N; i++ ) {
        string type;
        if (pa[i] == -1) type = "root";
        else if (e[i].size() == 0) type = "leaf";
        else type = "internal node";

        cout << "node " << i << ": parent = " << pa[i] << ", depth = " << d[i] << ", " << type << ", [";
        for ( int j = 0; j < e[i].size(); j++ ) {
            cout << (j != 0 ? ", " : "" ) <<  e[i][j];
        }
        cout << "]" << "\n";
    }
    return 0;
}
