#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    string ans = "win";
    if (a + b + c > 21) {
        ans = "bust";
    }
    cout << ans << endl;
    return 0;
}