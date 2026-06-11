#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int main() {
    int64_t n; cin >> n;

    vector<int> pf;
    for (int64_t i = 2; i * i <= n; ++i) {
        if (n % i) continue;
        int cnt = 0;
        while (n % i == 0) {
            ++cnt;
            n /= i;
        }
        pf.push_back(cnt);
    }
    if (n != 1) {
        pf.push_back(1);
    }

    int ans = 0;
    for (auto e : pf) {
        for (int i = 1; i <= e; ++i) {
            e -= i;
            ++ans;
        }
    }

    cout << ans << endl;
}

