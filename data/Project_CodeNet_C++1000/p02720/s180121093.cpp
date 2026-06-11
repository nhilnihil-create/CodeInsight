#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long> ans;

void dfs(long long x) {
    if (x > 3234566667) return;
    ans.push_back(x);
    for (int i = -1; i <= 1; i++) {
        int add = x % 10 + i;
        if (0 <= add && add <= 9) {
            dfs(x * 10 + add);
        }
    }
}

int main() {
    int K; cin >> K;
    for (long long i = 1; i < 10; i++) dfs(i);
    sort(ans.begin(), ans.end());
    cout << ans[K-1] << endl;
}
