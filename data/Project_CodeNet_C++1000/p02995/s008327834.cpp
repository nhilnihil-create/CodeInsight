#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

long long calcGcd(long long a, long long b) {
    // a > bにする
    if (a < b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    /* ユークリッドの互除法*/
    int r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

long long calcLcm(long long a, long long b) {
    return a * b / calcGcd(a, b);
}

int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    // cまたはdで割り切れるものの個数を求め、それをa以上b以下の整数の個数から引く
    // cまたはdで割り切れるものの個数はベン図より
    // cで割り切れるものの個数+dで割り切れるものの個数 - cでもdでも割り切れるものの個数で求められる
    // 1からbまでの範囲の個数から1からaまでの範囲の個数を引けば求める範囲の個数となる

    // a以上b以下の整数の個数
    long long all = b - a + 1;

    // c, d, cとdで割り切れるものの個数
    long long divided_c, divided_d, divided_lcm;

    // b以下の個数 - a未満の個数
    divided_c = b / c - (a - 1) / c;
    divided_d = b / d - (a - 1) / d;
    divided_lcm = b / calcLcm(c, d) - (a - 1) / calcLcm(c, d);

    long long ans = all - (divided_c + divided_d - divided_lcm);

    cout << ans << endl;
}
