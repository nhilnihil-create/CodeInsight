#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void dfs(int s, vector<vector<int> > &G, ll *tmp, int *seen) {
    seen[s] = 1;
    for (int i = 0; i < (int)G[s].size(); i++) {
        int v = G[s][i];
        if (seen[v])
            continue;
        tmp[v] += tmp[s];
        dfs(v, G, tmp, seen);
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<vector<int> > G(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;   cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }

    ll *tmp = new ll[N];
    int *seen = new int[N];
    for (int i = 0; i < N; i++)
        tmp[i] = 0, seen[i] = 0;

    for (int i = 0; i < Q; i++) {
        int x, p;  cin >> p >> x;
        tmp[p-1] += x;
    }

    dfs(0, G, tmp, seen);

    for (int i = 0; i < N; i++)
        cout << tmp[i] << " ";
    cout << endl;

    return 0;
}