#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> vi;
const int MAX_V = 10000;

int V, E;
vi G[MAX_V];
int deg[MAX_V];
bool used[MAX_V];

void solve() {
   for (int i = 0; i < V; i++) {
       if (!used[i] && deg[i] == 0) {
           cout << i << endl;
           used[i] = true;

           for (auto to : G[i]) {
               deg[to]--;
           }

           i = -1;
       }
   } 
}

int main() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;

        G[s].push_back(t);
    }

    for (int i = 0; i < V; i++) {
        for (auto to : G[i]) {
            deg[to]++;
        }
    }

    solve();
}