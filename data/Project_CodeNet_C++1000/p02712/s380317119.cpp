#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll sum = 0, n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i % 3 != 0 && i % 5 != 0) {
            sum += i;
        }
    }
    cout << sum;
}
