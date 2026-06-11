#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    int a, b;
    cin >> a >> b;
    if (a % 2 != b % 2)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << (a + b) / 2 << endl;

    return 0;
}