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
    string ans = "Yes";
    for (int i = n - 1; i > 0; i--) {
        if (h[i - 1] - h[i] > 1) {
            ans = "No";
            break;
        } else if (h[i - 1] - h[i] == 1) {
            h[i - 1]--;
        }
    }
    cout << ans << endl;
    return 0;
}