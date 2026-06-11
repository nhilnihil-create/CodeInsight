#include <bits/stdc++.h>

using namespace std;

int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    set<long long> a1 = {2,4,5,7,9};

    set<long long> a2 = {0,1,6,8};

    set<long long> a3 = {3};

    long long n;

    cin >> n;

    long long last = n%10;

    if(a1.find(last)!=a1.end()) {

        cout << "hon" << '\n';

    } else if(a2.find(last)!=a2.end()) {

        cout << "pon" << '\n';

    } else {

        cout << "bon" << '\n';

    }

    return 0;

}

