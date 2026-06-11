#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    int sum = 0;
    for (int i = 0; i < n; i++) cin >> w[i], sum += w[i];

    int ret = 1145141919, now = 0;
    for (int i = 0; i <= n; i++) {
        ret = min(ret, abs(now - sum));
        if (i < n)now += w[i], sum -= w[i];
    }

    cout << ret << endl;
    return 0;
}