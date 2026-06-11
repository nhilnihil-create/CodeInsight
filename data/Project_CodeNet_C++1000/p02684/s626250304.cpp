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
    int n;
    ll k;
    cin >> n >> k;
    vector<int>a(n), cnt(n, 0);
    rep(i, n)cin >> a[i];
    int i = 0, w = 0, r = 0, cnk = 0, str = 0;//iは行った町のNo、wはワープした回数、rはループに入るまで
    if (n < k) {
        while (cnt[i] < 2) {//二回ループさせる
            cnt[i]++;
            if (cnt[i] == 2) {
                cnk++;
                w++;
                if (cnk == 1)str = i;
            }
            i = a[i] - 1;
            r++;
        }
        r = r - 2 * w;
        ll q = (ll)(k - r) % w;
        i = str;
        while (q > 0) {
            q--;
            i = a[i] - 1;
        }
    }
    else {
        while (k > 0) {
            k--;
            i = a[i] - 1;
        }
    }
    cout << i + 1 << endl;

    return 0;
}