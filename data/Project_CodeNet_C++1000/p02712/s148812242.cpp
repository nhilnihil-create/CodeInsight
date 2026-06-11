/**
*    author:  Taichicchi
*    created: 09.09.2020 20:25:15
**/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;

    ll ans = 0;

    for(ll i=1;i<=N;++i) {
        if((i % 3 != 0) & (i % 5 != 0)) {
            ans += i;
        }
    }

    cout << ans << endl;
    return 0;
}