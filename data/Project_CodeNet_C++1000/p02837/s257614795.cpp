#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
using P = pair<int, int>;
int N;
vector<vector<P>> V;
bool judge(int bit) {
    for (int i = 0; i < N; ++i) {
        if (!(bit & (1 << i))) continue;
        for (P xy : V[i]) {
            int x = xy.first;
            int y = xy.second;
            if (y == 1 && !(bit & (1 << x))) return false;
            if (y == 0 && (bit & (1 << x))) return false;
        }
    }
    return true;
}
int main() {
    cin >> N;
    V.resize(N);
    for (int i = 0; i < N; ++i) {
        int A; cin >> A;
        V[i].resize(A);
        for (int j = 0; j < A; ++j) {
            cin >> V[i][j].first >> V[i][j].second;
            V[i][j].first--;
        }
    }
    int cnt = 0;
    for (int i = 0; i < (1 << N); ++i) {
        if (judge(i)) {
            int count = 0;

            for (int j = 0; j < N; ++j) if (i & (1 << j)) count++;

            cnt = max(cnt, count);
        }
    }
    cout << cnt << endl;
}