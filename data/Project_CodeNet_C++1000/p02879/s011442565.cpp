#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    int a, b;
    cin >> a >> b;

    if (a >= 10 || b >= 10)
        cout << -1 << endl;
    else
        cout << a * b << endl;

    return 0;
}