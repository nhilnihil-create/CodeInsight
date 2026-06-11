#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int p, q, r;
    cin >> p >> q >> r;
    cout << min(p + q, min(q + r, r + p)) << endl;
}