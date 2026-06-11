#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    int tap = 1;
    while (b > tap) {
        tap += a - 1;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}