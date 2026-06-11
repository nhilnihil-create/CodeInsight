#include <bits/stdc++.h>

using namespace std;

int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    vector<string> a = {"Sunny", "Cloudy", "Rainy"};

    string b;

    cin >> b;

    for(long long i = 0 ; i < a.size() ; i++) {

        if(a[i]==b) {

            cout << a[(i+1)%3] << '\n';

            return 0;

        }

    }

    return 0;

}

