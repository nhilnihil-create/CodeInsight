#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void start() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int32_t main() {
    start();
    long long a, b, c;
    cin >> a >> b >> c;
    if (a + b + c >= 22)cout << "bust";
    else cout << "win";
    return 0;
}