#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll X;
    cin >> X;
    for (int i = -200; i <= 200; i++) {
        for (int j = -200; j <= 200; j++) {
            ll a = pow(i, 5), b = pow(j, 5);
            if (a - b == X) {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
}