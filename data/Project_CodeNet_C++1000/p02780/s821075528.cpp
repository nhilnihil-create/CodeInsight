#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int sum = 0, sum_max = 0;
    for (int i = 0; i < k; i++) {
        sum += p[i];
    }
    sum_max = sum;
    for (int i = 0; i < n - k; i++) {
        sum = sum - p[i] + p[i + k];
        if (sum > sum_max) sum_max = sum;
    }
    cout << setprecision(15) << (sum_max + k) / 2.0 << endl;
    return 0;
}