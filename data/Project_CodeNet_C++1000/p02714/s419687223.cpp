#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

int main() {
    int n;
    string s;
    cin >> n >> s;

    long long red = 0, green = 0, blue = 0;
    for (auto color : s) {
        if (color == 'R') red++;
        if (color == 'G') green++;
        if (color == 'B') blue++;
    }

    // 1つ目の条件を満たす組の数はr*g*bで求められる
    long long condition1 = red * green * blue;

    // ２つ目の条件を満たさないものを求め、それを1つ目の中から引く
    // 判定を簡単にするためにr = 1; g = 2, b = 4と置き換えておく
    rep(i, n) {
        if (s[i] == 'R') s[i] = 1;
        if (s[i] == 'G') s[i] = 2;
        if (s[i] == 'B') s[i] = 4;
    }

    // j - i = k - jとなるものを調べる
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // i番目とj番目が一致
            if (s[i] == s[j]) continue;
            // i と j を固定しているのでk = 2 j - i となる
            int k = 2 * j - i;
            // kがn以上だと組を作れない
            if (k >= n) continue;
            if (s[i] + s[j] + s[k] == 7) condition1--;
        }
    }
    cout << condition1 << endl;
}
