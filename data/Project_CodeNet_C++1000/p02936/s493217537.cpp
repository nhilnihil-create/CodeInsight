#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<vector<ll>> E(N);
    for(int i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    vector<ll> V(N, 0);
    for(int i = 0; i < Q; i++) {
        ll p, x;
        cin >> p >> x;
        p--;
        V[p] += x;
    }
    vector<int> L(N, 0);
    queue<ll> q;
    q.push(0);
    L[0] = 1;
    while(!q.empty()) {
        ll u = q.front();
        q.pop();
        for(ll v : E[u]) {
            if(L[v] == 0) {
                L[v] = 1;
                V[v] += V[u];
                q.push(v);
            }
        }
    }
    for(int i = 0; i < N; i++) {
        if(i == 0)
            cout << V[i];
        else
            cout << " " << V[i];
    }
    cout << endl;
}