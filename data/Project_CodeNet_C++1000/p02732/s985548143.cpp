#pragma warning(disable: 4996)
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <math.h>
#include <algorithm>

using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    ll ans = 0;
    vector<ll>a(n);
    vector<ll>cnt(n);
    rep(i, n)cnt[i] = 0;
    rep(i, n) {
        cin >> a[i];
        cnt[a[i] - 1]++;
    }
    rep(i,n)ans += cnt[i] * (cnt[i] - 1) / 2;//先に一つ除かない場合の数を求める
    rep(i, n) {
        ll ans2 = 0;
        ans2 = ans - cnt[a[i] - 1] * (cnt[a[i] - 1] - 1) / 2;
        if (cnt[a[i] - 1] != 0) ans2 += (cnt[a[i] - 1] - 1) * (cnt[a[i] - 1] - 2) / 2;
        cout << ans2 << endl;
    }
    return 0;
}