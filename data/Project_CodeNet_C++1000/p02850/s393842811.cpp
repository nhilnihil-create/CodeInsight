#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MX = 1e9;

#include <math.h>
#define PI 3.14159265358979323846264338327950L

long long gcd(long long a, long long b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}
long long digits(long long m) {
    long long cnt = 0;
    while (m) {
        cnt++;
        m /= 10;
    }
    return cnt;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    vector<pair<int, int>> printerino(N);
    for (int i = 1; i < N; i++) {
        int x, y;
        cin >> x >> y;
        x--;y--;
        G[x].push_back(y);
        G[y].push_back(x);
        printerino[i] = make_pair(x, y);
    }
    int K = 0;

    map<pair<int, int>, int> I;
    vector<int> cs(N, 0);

    vector<bool> visited(N);
    queue<int> Q;
    Q.emplace(0);
    visited[0] = true;
    while (!Q.empty()) {
        int v = Q.front();Q.pop();
        if (K < G[v].size()) K = G[v].size();
        int cur = 1;
        for (auto u : G[v]) {
            if (visited[u]) continue;
            if (cur == cs[v]) cur++;
            I[make_pair(v, u)] = cur;
            I[make_pair(u, v)] = cur;
            cs[u] = cur;
            cur++;
            Q.emplace(u);
            visited[u] = true;
        }
    }
    cout << K << "\n";
    for (int i = 1; i < N; i++) {
        cout << I[printerino[i]] << "\n";
    }
    return 0;
}