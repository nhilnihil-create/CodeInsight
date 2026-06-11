#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    int *x = new int[n + 5];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    int min = INT_MAX;
    for (int i = 0; i <= 100; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += (x[j] - i) * (x[j] - i);
        }
        min = (min < sum) ? min : sum;
    }
    cout << min << endl;
    return 0;
}