#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n, d;
    cin >> n >> d;
    cout << (n - 1) / (2 * d + 1) + 1 << endl;
    return 0;
}