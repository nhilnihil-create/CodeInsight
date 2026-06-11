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
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; ++i) cin >> P[i];
    vector<int> Q(N);
    for (int i = 0; i < N; ++i) cin >> Q[i];
    vector<int> V(N);
    for (int i = 0; i < N; ++i) V[i] = i+1;
    int count = 0;
    int a = 0;
    int b = 0;
    do {
        ++count;
        if (V == P) a = count;
        if (V == Q) b = count;
    } while (next_permutation(V.begin(), V.end()));
    cout << abs(a - b) << endl;
    return 0;
}