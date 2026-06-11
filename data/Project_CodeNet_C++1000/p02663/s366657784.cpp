#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int h, m, h2, m2, k;
    cin >> h >> m >> h2 >> m2 >> k;
    cout << (h2 - h) * 60 + m2 - m - k << endl;
    return 0;
}