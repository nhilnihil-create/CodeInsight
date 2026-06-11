#include <bits/stdc++.h>

using namespace std;


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int k;
    cin >> k;
    long long sum =0;
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            for (int l = 1; l <= k; ++l) {
                sum += __gcd(__gcd(i, j),l);
            }
        }
    }
    cout << sum << endl;
}