#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處

int n, k;
int a[505];

int try_d(int d) {
    // printf("try %d\n", d);
    int sub = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int j = 0; j < n; j++) {
        int lower = a[j] / d * d;
        int higher = a[j] % d == 0 ? a[j] : (a[j] / d + 1) * d;
        // printf("lower = %d, higher = %d\n", lower, higher);
        sub += (a[j] - lower);
        if (higher > a[j]) {
            // printf("pq.push %d\n", higher - a[j]);
            pq.push(higher - a[j]);
        }
    }
    int ret = 0;
    while (sub > 0) {
        sub -= d;
        ret += pq.top();
        pq.pop();
    }
    // printf("d = %d, diff = %d\n", d, ret);
    return ret;
}

int main() {
    cin >> n >> k;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int ans = 1;
    for (int i = 1; i * i <= sum; i++) {
        if (sum % i == 0) {
            if (try_d(i) <= k) { ans = max(ans, i); }
            if (try_d(sum / i) <= k) { ans = max(ans, sum / i); }
        }
    }
    cout << ans << endl;
}
