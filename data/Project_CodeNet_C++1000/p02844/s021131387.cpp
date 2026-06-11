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
    string S;
    cin >> N >> S;
    int res = 0;
    for (int i = 0; i < 1000; ++i) {
        int a[3] = {i/100, (i/10)%10, i%10};
        int process = 0;
        for (int j = 0; j < N; ++j) {
            if (process <= 2 && a[process] == (int)(S[j]-'0')) process++;
        }
        if (process == 3) res++;
    }
    cout << res << endl;
    return 0;
}