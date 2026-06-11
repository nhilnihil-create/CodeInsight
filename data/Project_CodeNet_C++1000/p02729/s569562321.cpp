#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int comb2(int n) {
    if (n < 2) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        return n * (n - 1) / 2;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << comb2(n) + comb2(m) << endl;
    return 0;
}