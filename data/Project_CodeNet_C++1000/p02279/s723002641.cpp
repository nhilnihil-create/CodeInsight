#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
  
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
  
using namespace std;
  
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;
  
const int INF=1<<29;
const double EPS=1e-9;
  
const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int N;
std::vector<vector<int> > G;
std::vector<int> parent;
std::vector<int> depth;
std::vector<int> type;

void dfs(int i, int d) {
    depth[i] = d;
    for (int j = 0; j < G[i].size(); j++) {
        parent[G[i][j]] = i;
        dfs(G[i][j], d + 1);
    }
    if (G[i].size() == 0) {
        type[i] = 0;
    } else {
        type[i] = 1;
    }
}

int main() {

    cin >> N;
    for (int i = 0; i < N; i++) {
        G.push_back(vector<int>());
        parent.push_back(-1);
        depth.push_back(0);
        type.push_back(0);
    }
    std::vector<int> notroot(N, 0);
    for (int i = 0; i < N; i++) {
        int id, k;
        cin >> id >> k;
        for (int j = 0; j < k; j++) {
            int child;
            cin >> child;
            notroot[child] = 1;
            G[id].push_back(child);
        }
    }
    
    int root;
    for (int i = 0; i < N; i++) {
        if (notroot[i] == 0) {
            root = i;
            break;
        }
    }
    dfs(root, 0);

    for (int i = 0; i < N; i++) {
        cout << "node " << i << ": ";
        cout << "parent = " << parent[i] << ", ";
        cout << "depth = " << depth[i] << ", ";
        
        if (depth[i] == 0) {
            cout << "root, ";
        } else {
            if (type[i] == 0) {
                cout << "leaf, ";
            } else {
                cout << "internal node, ";
            }
        }
        cout << "[";
        for (int j = 0; j < G[i].size(); j++) {
            cout << G[i][j];
            if (j != G[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}