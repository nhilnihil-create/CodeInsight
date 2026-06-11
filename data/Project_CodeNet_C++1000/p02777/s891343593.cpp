#include <bits/stdc++.h>

using namespace std;

int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    string c1;

    cin >> c1;

    string c2;

    cin >> c2;

    long long cc1;

    cin >> cc1;

    long long cc2;

    cin >> cc2;

    string mop;

    cin >> mop;

    if(mop==c1) {

        cc1--;

    } else {

        cc2--;

    }

    cout << cc1 << ' ' << cc2 << '\n';

    return 0;

}

