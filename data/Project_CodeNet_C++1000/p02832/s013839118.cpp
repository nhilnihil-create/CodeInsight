#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int num = 1, cnt = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == num) {
            num++;
        } else {
            cnt++;
        }
    }
    if (num == 1) cnt = -1;
    cout << cnt << endl;
    return 0;
}