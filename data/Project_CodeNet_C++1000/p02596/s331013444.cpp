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

int main() {
    long long K;
    cin >> K;

    //  Kが7の倍数ならばL = 9K/7, そうでなければL = 9Kと定義し
    // 10^i をLで割った余りが1であるような最小の正の整数iを求める
    // オイラーの定理より10とLが互いに素であれば必ず見つかる

    // Lで割った余りをとる演算は10倍するごとに行う

    long long L;

    // Lの定義
    if (K % 7 == 0) {
        L = 9 * K / 7;
    } else if (K % 7 != 0) {
        L = 9 * K;
    };

    // 10とLが互いに素ではない場合
    if (calcGcd(L, 10) != 1) {
        cout << "-1" << endl;
        return 0;
    }

    // 互いに素であるとき必ず見つかる
    long long count = 0;
    long long reminder = 1;
    while (true) {
        count++;
        reminder = (reminder * 10) % L;

        if (reminder == 1) break;
    }
    cout << count << endl;
}
