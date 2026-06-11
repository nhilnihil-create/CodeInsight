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
    ll N;
    cin >> N;
    if (N % 2 == 1) {
        cout << 0 << endl;
        return 0;
    } else {
        ll sum = 0;
        ll base = 5;
        ll n = N;
        while (n >= base) {
            sum += (n / base) / 2;
            base *= 5;
        }

        cout << sum << endl;
    }
}