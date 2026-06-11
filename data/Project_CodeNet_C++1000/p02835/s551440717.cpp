#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k; cin >> n >> m >> k;
    if (n + m + k > 21) {
        cout << "bust" << "\n";
    } else {
        cout << "win" << "\n";
    }
}