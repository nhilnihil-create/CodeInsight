//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <deque>
#include <map>
using namespace std;

#define ii pair <int, int>
#define lli long long
#define pb push_back
#define X first
#define Y second

const int Mod = 1E9 + 7;
const int Inf = 1E9 + 7;
const int N = 5E5 + 10;

int n;
lli a[N], Bit[65];

void Input()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

void Solve()
{
    lli res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 60; j++) if (a[i] & (1ll << j)) {
            res = (res + (lli) (1ll << j) % Mod * (i - 1 - Bit[j]) % Mod ) % Mod;
            Bit[j]++;
        }
        else res = (res + (1ll << j) % Mod * Bit[j] % Mod) % Mod;
    }
    cout << res;
}

#define task "test"
int main()
{
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int testcase = 1;
    /// cin >> testcase;
    while (testcase--) {
        Input();
        Solve();
    }
}


