#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int K; cin >> K;
    queue<int64_t> que;
    for(int i = 1; i < 10; ++i) que.push(i);
    K--;
    while(K--) {
        auto t = que.front();
        que.pop();
        int l = t % 10;
        for(int i = max(0, l - 1); i <= min(9, l + 1); ++i) {
            que.push(10 * t + i);
        }
    }
    cout << que.front() << '\n';
    return 0;
}
