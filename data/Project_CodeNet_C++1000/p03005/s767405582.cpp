#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    int n, k;
    cin >> n >> k;
    n -= k;
    cout << (k == 1 ? 0 : n) << endl;
}
