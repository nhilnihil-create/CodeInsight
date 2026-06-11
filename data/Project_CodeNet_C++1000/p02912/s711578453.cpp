#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    priority_queue<long long> price_que;
    long price;
    for (int i = 0; i < n; ++i) {
        cin >> price;
        price_que.push(price);
    }

    for (int i = 0; i < m; ++i) {
        long target_price = price_que.top();
        price_que.pop();

        price_que.push(target_price / 2);
    }

    long ans = 0;
    while (!price_que.empty()) {
        ans += price_que.top();
        price_que.pop();
    }

    cout << ans << endl;

    return 0;
}