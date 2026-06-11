#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n, k;
    cin >> n >> k;

    int o = 0;
    while (n > 0) {
        n /= k;
        o++;
    }
    cout << o << endl;
    return 0;
}