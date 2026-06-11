#include <bits/stdc++.h>

using namespace std;

int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    set<long long> a = {1,3,2};

    long long b;

    cin >> b;

    long long c;

    cin >> c;

    a.erase(b);

    a.erase(c);

    cout << *a.begin() << '\n';

    return 0;

}

