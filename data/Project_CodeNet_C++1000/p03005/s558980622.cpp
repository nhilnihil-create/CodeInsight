#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;
    if (k == 1) cout << 0 << endl;
    else cout << n - k << endl;
}