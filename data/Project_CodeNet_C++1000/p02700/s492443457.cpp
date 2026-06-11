#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x = (a + d - 1) / d;
    int y = (b + c - 1) / b;
    if (x >= y) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}