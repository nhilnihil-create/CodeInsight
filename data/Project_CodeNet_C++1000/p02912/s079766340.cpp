#include <iostream>
#include <queue>
#include <cstdint>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    uint64_t sum = 0;
    priority_queue<int> que;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        sum += a;
        que.push(a);
    }

    for (int i = 0; i < m; ++i) {
        int c = que.top(); que.pop();
        sum -= c;
        c /= 2;
        sum += c;
        que.push(c);
    }

    cout << sum << endl;
}

