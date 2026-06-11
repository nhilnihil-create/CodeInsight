#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> next(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> next[i]; next[i]--;
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    long long ans = -1e17;
    for (int i = 0; i < n; ++i) {
        int now = i;
        long long cycle_sum = 0;
        int cycle_len = 0;
        while (true) {
            cycle_sum += c[now];
            cycle_len++;
            now = next[now];
            if (now == i) break;
        }
        long long path_sum = 0;
        int path_len = 0;
        while (true) {
            path_sum += c[now];
            path_len++;
            if (path_len > k) break;
            int laps = (k - path_len) / cycle_len;
            long long score = path_sum + max(cycle_sum, 0ll) * laps;
            ans = max(ans, score);
            now = next[now];
            if (now == i) break;
        }
    }
    cout << ans << endl;
}