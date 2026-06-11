#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> d(101, -1);
vector<vector<int> > c(101, vector<int>(101, 0));

int n, u, k, v;
typedef pair<int, int> P; 
int bfs(void) {
    queue<P> que;
    que.push(P(0, 0));
    while(que.size()>0) {
        P p = que.front(); que.pop();
        if(d[p.first]==-1) d[p.first] = p.second;
        for(int i=0; i<n; ++i) {
            if(c[p.first][i]==1 && d[i]==-1) que.push(P(i, d[p.first]+1));
        }
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; ++i) {
        cin >> u >> k;
        for(int j=0; j<k; ++j) {
            cin >> v;
            c[i][v-1] = 1;
        }
    }
    bfs();
    for(int i=0; i<n; ++i) {
        cout << i+1 << " " << d[i] << endl;
    }
    return 0;
}