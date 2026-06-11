#include <bits/stdc++.h>

using namespace std;

int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    long long k;

    cin >> k;

    long long A;

    cin >> A;

    long long B;

    cin >> B;

    for(long long i=A; i<=B; i++) {

        if(i%k==0) {

            cout << "OK" << '\n';

            return 0;

        }

    }

    cout << "NG" << '\n';

    return 0;

}

