#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int k, x;
    cin >> k >> x;
    string ans = "No";
    if (500 * k >= x) {
        ans = "Yes";
    }
    cout << ans << endl;
}