#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int64_t S; cin >> S;
    auto OK = [&](int64_t x) -> bool {
        return x * 1e9 < S;
    };
    int64_t l = 0, r = 1e9;
    while(r - l > 1) {
        int64_t c = (l + r) / 2;
        if(OK(c)) l = c;
        else r = c;
    }
    int64_t x1 = 1e9;
    int64_t y1 = 1;
    int64_t y2 = r;
    int64_t x2 = x1 * y2 - S;

    printf("0 0 %ld %ld %ld %ld\n", x1, y1, x2, y2);
    cerr << x1 * y2 - x2 * y1 << '\n';
    return 0;
}
