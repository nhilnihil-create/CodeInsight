#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, a, b, min_x = INT64_MAX, max_x = INT64_MIN,
                     min_y = INT64_MAX, max_y = INT64_MIN;
    cin >> n;
    for (auto i = 0; i < n; i++) {
        cin >> a >> b;
        min_x = min(a - b, min_x);
        max_x = max(a - b, max_x);
        min_y = min(a + b, min_y);
        max_y = max(a + b, max_y);
    }
    cout << max(max_x - min_x, max_y - min_y) << endl;
    return 0;
}