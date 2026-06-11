#include <bits/stdc++.h>

using namespace std;

int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    long long n;

    cin >> n;

    long long cnt=0;

    for(long long i=1; i<=n; i++) {

        cnt += (i&1);

    }

    cout << fixed << setprecision(12);

    cout << cnt / (long double)n << '\n';

    return 0;

}

