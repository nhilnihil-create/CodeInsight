#include <bits/stdc++.h>

using namespace std;

int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    long long a;

    cin >> a;

    long long b;

    cin >> b;

    b*=2;

    a-=b;

    a= max(0LL,a);

    cout << a << '\n';

    return 0;

}

