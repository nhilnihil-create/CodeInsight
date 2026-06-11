#pragma warning(disable: 4996)
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
    ll l, r, ans = 2019;
    cin >> l >> r;
    if (r - l > 2019) {
        cout << 0 << endl;
        return 0;
    }
    l = l % 2019;
    r = r % 2019;
    if (r < l )ans = 0;
    else {
        for (int i = l; i < r; i++) {
            for (int j = i + 1; j <= r; j++) {
                ll tmp = i * j;
                tmp = tmp % 2019;
                ans = min(tmp, ans);
            }
       }
    }
    cout << ans << endl;

    return 0;
}