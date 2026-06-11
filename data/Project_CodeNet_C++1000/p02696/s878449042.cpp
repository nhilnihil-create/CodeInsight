#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    long a, b, n;
    cin >> a >> b >> n;
    cout << a * min(n, b - 1) / b;

    return 0;
}