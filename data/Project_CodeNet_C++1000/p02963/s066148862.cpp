#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    ll S;
    cin >> S;

    int y = (S + INF - 1) / INF;
    int x = y * INF - S;

    cout << "0 0 1000000000 1 " << x << " " << y << endl;

    return 0;
}