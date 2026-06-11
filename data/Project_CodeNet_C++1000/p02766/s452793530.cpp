#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int n, k, cnt = 0;
    cin >> n >> k;
    while (n > 0) {
        n /= k;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}