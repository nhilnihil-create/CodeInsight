#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MOD = 1000000009;
const long long INF = 1LL << 60;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        --A[i];
    }

    map<int, int> used;
    vector<int> path;
    int now = 0;
    while(used.count(now) == 0) {
        path.push_back(now);
        used[now]++;
        now = A[now];
    }

    int s = find(path.begin(), path.end(), now) - path.begin();
    int r = path.size() - s;

    if (K < s) {
        cout << path[K] + 1 << endl;
        return 0;
    } else {
        cout << path[(K-s) % r + s] + 1 << endl;
        return 0;
    }
}