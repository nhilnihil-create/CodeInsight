#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;
vector<vector<int> > G(MAX_N*(MAX_N-1)/2 + 1);
vector<int> dis(MAX_N*(MAX_N-1)/2 + 1, -1);
vector<bool> start(MAX_N*(MAX_N-1)/2 + 1, false);
vector<bool> done(MAX_N*(MAX_N-1)/2 + 1, false);

int dfs(int obj) {
    if (start[obj]) {
        if (!done[obj]) return -1;
        return dis[obj];
    } else {
        start[obj] = true;
        int k = 0;
        for (int x : G[obj]) {
            int l = dfs(x);
            if (l == -1) return -1;
            else k = max(k, l);
        }
        done[obj] = true;
        dis[obj] = k + 1;
        return dis[obj];
    }
}

int main() {
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        int a; cin >> a;
        int k = (max(a, i)-1)*(max(a, i)-2)/2 + min(a, i);
        for (int j = 0; j < N-2; j++) {
            int a; cin >> a;
            int l = (max(a, i)-1)*(max(a, i)-2)/2 + min(a, i);
            G[k].push_back(l);
            k = l;
        }
    }
    int k = 0;
    for (int i = 1; i <= N*(N-1)/2; i++) {
        if (dfs(i) == -1) {
            k = -1;
            break;
        } else {
            k = max(k, dfs(i));
        }
    }
    cout << k << endl;
}
