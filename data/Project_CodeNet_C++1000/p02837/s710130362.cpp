#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
typedef pair<int, int> P;
int N;
vector<P> G[20];

bool judge(int bit) {
    for (int i = 0; i < N; i++) {
        if (!(bit & (1 << i))) continue;

        for (P xy: G[i]) {
            int x = xy.first;
            int y = xy.second;
            if (((bit >> x) & 1) ^ y) return false;
        }
    }
    return true;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int A; cin >> A;
        for (int j = 0; j < A; j++) {
            int x, y; cin >> x >> y;
            G[i].push_back({x-1, y});
        }
    }

    int ans = 0;
    for (int bit = 0; bit < (1 << N); bit++) {
        int tmp = bitset<20>(bit).count();
        if (tmp <= ans) continue;
        if (judge(bit)) ans = max(ans, tmp);
    }
    cout << ans << endl;
}