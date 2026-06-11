#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
    int n, x, t;
    cin >> n >> x >> t;

    int total = 0;
    int time = 0;
    while (total < n) {
        total += x;
        time += t;
    }

    cout << time << "\n";
    return 0;
}
