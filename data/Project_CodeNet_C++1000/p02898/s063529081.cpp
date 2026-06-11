#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n, k;
    cin >> n >> k;
    int h;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> h;
        if (h >= k) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}