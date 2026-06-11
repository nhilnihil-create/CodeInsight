#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int a, b;
    cin >> a >> b;
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    for (int i = 0; i < b; i++) {
        cout << (char)('0' + a);
    }
    cout << endl;
    return 0;
}