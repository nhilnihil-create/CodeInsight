#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll X, C;
    cin >> X;
    C = X / 100;
    cout << (C * 100 <= X && X <= C * 105) << endl;
    return 0;
}
