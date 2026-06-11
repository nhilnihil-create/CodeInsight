#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {

    int k, x;
    cin >> k >> x;
    if (500 * k >= x) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}