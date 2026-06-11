#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll h;
    cin >> h;
    cout << fixed << setprecision(0) << pow(2, floor(log2(h)) + 1) - 1 << endl;
    return 0;
}