/*
    Problem 26
    https://atcoder.jp/contests/abc138/tasks/abc138_d
*/
#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 200005;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
vector<vector<int>> G(MAX, vector<int>());
vector<bool> visited(MAX);
vector<int> counter(MAX, 0);
/* function */
void bfs(int st) {
    queue<int> q;
    q.push(st);
    visited[st] = true;
    while (!q.empty()) {
        int from = q.front();
        q.pop();
        for (int to : G[from]) {
            if (visited[to]) continue;
            visited[to] = true;
            counter[to] += counter[from];
            q.push(to);
        }
    }
}
void dfs(int from) {
    visited[from] = true;
    for (int to : G[from]) {
        if (visited[to]) continue;
        counter[to] += counter[from];
        dfs(to);
    }
}
/* main */
int main(){
    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i < Q; i++) {
        int a, c;
        cin >> a >> c;
        a--;
        counter[a] += c;
    }
    // bfs(0);
    dfs(0);

    for (int i = 0; i < N; i++)
        cout << counter[i] << (i == N-1 ? '\n' : ' ');
}