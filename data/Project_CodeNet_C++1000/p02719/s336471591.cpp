#include <bits/stdc++.h>

using namespace std;


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    long long n, k;
    cin >> n >> k;
    n %= k;
    cout << min(n, abs(n - k));
}