#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto cmp = [&](int left, int right) {
        return b[left] < b[right];
    };
    priority_queue<int, vector<int>, decltype(cmp)> queue(cmp);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] != a[i]) {
            queue.emplace(i);
        }
    }
    long long result = 0;
    while (!queue.empty()) {
        auto top = queue.top();
        queue.pop();
        int sum = b[(top - 1 + n) % n] + b[(top + 1) % n];
        if ((b[top] - a[top]) % sum == 0) {
            result += (b[top] - a[top]) / sum;
            b[top] = a[top];
        } else if (b[top] > sum) {
            result += b[top] / sum;
            b[top] %= sum;
            if (b[top] < a[top]) {
                result = -1;
                break;
            }
            queue.emplace(top);
        } else {
            result = -1;
            break;
        }
    }
    cout << result;
    return 0;
}