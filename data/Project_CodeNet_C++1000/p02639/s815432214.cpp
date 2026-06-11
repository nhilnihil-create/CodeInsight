#include <bits/stdc++.h>

using namespace std;

int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    set<long long> s;

    for(long long i = 0 ; i < 6 ; i++) {

        s.insert(i);

    }

    vector<long long> a(5);

    for(long long i = 0 ; i < 5 ; i++) {

        cin >> a[i];

    }

    for(long long i = 0 ; i < a.size() ; i++) {

        if(s.find(a[i])!=s.end()) {

            s.erase(a[i]);

        }

    }

    cout << (*s.begin()) << '\n';

    return 0;

}

