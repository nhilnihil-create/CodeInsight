#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << fixed << setprecision(10) << ((double)n / 2) / (double)n
             << endl;
    } else {
        cout << fixed << setprecision(10) << (((double)n + 1) / 2) / (double)n
             << endl;
    }
    return 0;
}