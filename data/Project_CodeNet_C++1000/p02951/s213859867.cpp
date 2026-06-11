#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = c - (a - b);
    if (ans < 0) {
        ans = 0;
    }
    cout << ans << endl;
}