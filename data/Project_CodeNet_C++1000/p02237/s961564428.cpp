#include <bits/stdc++.h>

#define REP(i, n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
const int INF = 1e9;

using namespace std;
vector<int> adj[100];
int res[105][105] = {0};

int main() {
    int n; cin >> n;
    REP(i, n){
        int u, k;
        cin >> u >> k;
        REP(j, k) {
            int tmp;
            cin >> tmp;
            res[u][tmp] = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < n ; j++)
            cout << res[i][j] << " ";
        cout << res[i][n] << endl;
    }
    return 0;
}