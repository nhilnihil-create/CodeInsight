#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    rep(i, n) {
        cin >> a.at(i);
    }

    // i + Ai = j - Aj となればよい
    // L = i + Ai, R = j - Aj とおいて{値:個数}のmapで管理

    long long count = 0;
    map<long long, long long> L, R;

    for (long long i = 1; i < n + 1; i++) {
        // それまでのiを見て今回のiとL=Rになっているものがあるかを見る(無いなら0が足される)
        // Lの値と一致するものがあるかRの値を見てRの個数分を足し、その逆も行う
        count += R[i + a.at(i - 1)];
        count += L[i - a.at(i - 1)];

        // 個数を1増やす
        L[i + a.at(i - 1)]++;
        R[i - a.at(i - 1)]++;
    }

    cout << count << endl;
}
