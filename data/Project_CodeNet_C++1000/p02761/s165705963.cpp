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
    int N, M;
    cin >> N >> M;
    vector<int> s(M);
    vector<char> c(M);
    for (int i = 0; i < M; ++i) {
        cin >> s[i] >> c[i];
        --s[i];
    }
    int res = -1;
    for (int i = 0; i < 1000; ++i) {
        string num = to_string(i);
        if (num.length() != N) continue;
        bool check = true;
        for (int j = 0; j < M; ++j) {
            if (num[s[j]] != c[j]) check = false;
        }
        if (check) {
            res = i;
            break;
        }
    }
    cout << res << endl;
    return 0;
}