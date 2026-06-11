#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int cnt_max = 0;
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (h[i] < h[i + 1]) {
            cnt_max = max(cnt_max, cnt);
            cnt = 0;
        } else {
            cnt++;
        }
    }
    cnt_max = max(cnt_max, cnt);
    cout << cnt_max << endl;
    return 0;
}