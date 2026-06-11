/**
*    author:  boutarou
*    created: 10.07.2020 09:44:51
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); i++)
using lint = long long;
using P = pair<int, int>;

int main() {
    lint x;
    lint now = 100;
    cin >> x;
    for (int i = 1;;i++) {
        now += now / 100;
        if (now >= x) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}