#include <bits/stdc++.h>

using namespace std;

int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    string a;

    cin >> a;

    string b;

    cin >> b;

    b.pop_back();

    if(a==b) {

        cout << "Yes" <<'\n';

    } else {

        cout << "No" <<'\n';

    }

    return 0;

}

