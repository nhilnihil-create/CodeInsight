#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i, a, b) for(int i = a; i < (int)b; ++i)

typedef long long ll;

const int Inf = 1e9;
const double EPS = 1e-9;
const int MAX = 100001;

void bfs(int);

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int bitCount(long bits) {
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
}

vector<int> g[MAX];
bool visited[MAX];
int entry[MAX];
list<int> out;
int v;

void tsort() {
    rep (i, v) entry[i] = 0;
    rep (i, v) {
        rep (j, g[i].size()) {
            int c = g[i][j];
            entry[c]++;
        }
    }
    rep (i, v) {
        if (entry[i] == 0 && !visited[i]) bfs(i);
    }

    for (auto iter = out.begin(); iter != out.end(); iter++) {
        cout << *iter << endl;
    }

}

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        out.push_back(t);
        rep (i, g[t].size()) {
            int u = g[t][i];
            entry[u]--;
            if (entry[u] == 0 && !visited[u]) {
                q.push(u);
                visited[u] = true;
            }
        }
    }

}

int main() {
    int e;
    cin >> v >> e;
    rep (i, v) visited[i] = false;
    rep (i, e) {
        int s, t;
        cin >> s >> t;
        g[s].push_back(t);
    }
    tsort();
    
    return 0;
}

