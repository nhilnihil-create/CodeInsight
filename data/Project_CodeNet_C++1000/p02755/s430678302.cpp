#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    int a, b;
    int ans = 0;
    cin >> a >> b;
    for (int i = 1; i <= 1000; ++i) {
        int tmp = i * 0.08;
        if (floor(i * 0.08) == a && floor(i * 0.1) == b) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}