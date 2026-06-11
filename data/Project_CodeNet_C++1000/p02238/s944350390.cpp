#include <iostream>
#include <ios>
#include <vector>
using namespace std;

void read_data(int n, vector<vector<int>> & Es){
    int u = 0, k = 0, v = 0;
    while (n--){
        cin >> u;
        cin >> k;
        while (k--){
            cin >> v;
            Es[u - 1].push_back(v - 1);
        }
    }
}

void display_result(int n, vector<int> & d, vector<int> & f)

{
    for (int i = 0; i != n; ++i){
        cout << i + 1 << ' ' << d[i] << ' ' << f[i] << endl;
    }
}

void dfs(int node, int & time, vector<vector<int>> & Es, vector<int> & d, vector<int> & f ){
    if (d[node]) return;
    d[node] = time;
    ++time;
    for (auto next_node : Es[node]){
        dfs(next_node, time, Es, d, f);
    }
    f[node] = time;
    ++time;
}

int main()
{
    ios::sync_with_stdio(false);
    int n = 0;
    cin >> n;
    vector< vector<int> > Es(n);
    vector<int> d(n, 0);
    vector<int> f(n, 0);
    read_data(n, Es);
    int time = 1;
    for (int node = 0; node != n; ++node) dfs(node, time, Es, d, f);
    display_result(n, d, f);
    
    return 0;
}