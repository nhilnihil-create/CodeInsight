#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll X;
    cin >> X;
    ll div, mod;
    div = X / 100;
    mod = X % 100;
    ll ma = div * 5;
    if (mod <= ma)
        cout << 1 << endl;
    else
        cout << 0 << endl;
}