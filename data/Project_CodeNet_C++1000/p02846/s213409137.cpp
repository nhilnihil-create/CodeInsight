#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include <set>

#define DIV 1000000007
using namespace std;
using ll = long long;

int main() {
    ll T1, T2;
    cin >> T1 >> T2;

    ll A1, A2;
    cin >> A1 >> A2;

    ll B1, B2;
    cin >> B1 >> B2;

    ll c1 = A1 - B1, c2 = A2 - B2;
    ll ans = 0;

    if (c1 == 0)
        cout << "infinity" << endl;

    else if (c1 > 0) {
        if (c1 * T1 + c2 * T2 > 0)
            cout << 0 << endl;
        else if (c1 * T1 + c2 * T2 == 0)
            cout << "infinity" << endl;
        else {
            ll turn = (-1)*(c1 * T1 + c2 * T2);
            ans = (c1 * T1) / turn;
            if ((c1 * T1) % turn == 0)ans = ans * 2;
            else ans = ans * 2 + 1;
            cout << ans << endl;
        }

    }

    else {
        if (c1 * T1 + c2 * T2 < 0)
            cout << 0 << endl;
        else if (c1 * T1 + c2 * T2 == 0)
            cout << "infinity" << endl;
        else {
            ll turn = c1 * T1 + c2 * T2;
            ans = ((-1)*c1 * T1) / turn;
            if (((-1)*c1 * T1) % turn == 0)ans = ans * 2;
            else ans = ans * 2 + 1;
            cout << ans << endl;
        }

    }
}
