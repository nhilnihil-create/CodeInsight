#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using li = long long int;
using uli = unsigned long long int;
using namespace std;

int main() {
    fastIO;
    int n, m;
    cin >> n >> m;
    while (m--) {
        int day;
        cin >> day;
        n -= day;
    }
    if (n < 0)
        cout << -1;
    else
        cout << n;
}