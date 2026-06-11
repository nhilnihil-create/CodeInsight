#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    double n, d, ans = 0;
    cin >> n >> d;

    cout << ceil(n / (2 * d + 1)) << endl;
    return 0;
}
