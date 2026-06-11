#include <bits/stdc++.h>

using namespace std;

int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    vector<long long> a(3);

    for(long long i = 0 ; i < 3 ; i++) {

        cin >> a[i];

    }

    set<long long> b(a.begin(),a.end());

    if(b.size()==2) {

        cout << "Yes" <<'\n';

    } else {

        cout << "No" <<'\n';

    }

    return 0;

}

