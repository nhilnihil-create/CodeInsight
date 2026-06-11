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
    vector<int> B(N-1);
    for (int i = 0; i < N-1; ++i) cin >> B[i];
    ll res = B[0];
    for (int i = 0; i+1 < N-1; ++i) {
        res += min(B[i], B[i+1]);
    }
    res += B.back();
    cout << res << endl;
    return 0;
}