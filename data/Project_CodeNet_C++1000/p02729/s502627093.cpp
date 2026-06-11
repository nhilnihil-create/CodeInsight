#include <bits/stdc++.h>

using namespace std;

long long nC2(long long n) {

    return (n*(n-1))/2;

}

int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    long long n;

    cin >> n;

    long long m;

    cin >> m;

    long long res = nC2(n) + nC2(m);

    cout << res << '\n';

    return 0;

}

