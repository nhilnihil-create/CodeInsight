#include "bits/stdc++.h"
using namespace std;

int main() {
    int n, res = 0;
    cin >> n;
    for (int a = 1; a < n; ++a) {
        res += (n-1)/a;
    }
    cout << res;
}