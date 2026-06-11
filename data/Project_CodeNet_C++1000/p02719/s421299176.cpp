#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, m;
    cin >> n >> m;
    n = n % m;
    cout << min(n, m - n) << "\n";
    return 0;
}
