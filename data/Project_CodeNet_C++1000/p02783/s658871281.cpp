#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    int h, a;
    cin >> h >> a;
    if (h % a == 0) {
        cout << h / a << endl;
    } else {
        cout << h / a + 1 << endl;
    }

    return 0;
}