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
#include <bitset>
#include <queue>

using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
    ll x;
    cin >> x;
    rep(i, 152) {
        ll a = 1, b = 1;
        rep(p, 5)a *= i;
        rep(j, 151) {
            b = 1;
            rep(q, 5)b *= j;
            if (a - b == x) {
                cout << i << ' ' << j << endl;
                return 0;
            }
            if (a + b == x) {
                cout << i << ' ' << -j << endl;
                return 0;
            }
        }
    }


    return 0;
}