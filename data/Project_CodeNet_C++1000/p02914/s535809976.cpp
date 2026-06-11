#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll sum = 0;
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
        sum ^= A[i];
    }

    //sumで1が立っているbitはどう分けても1になるので考えなくて良い
    //つまり各Aについてsumを反転させたものだけでマスクをかける
    for (ll i = 0; i < N; i++) {
        A[i] &= ~sum;
    }

    //残ったものについて最適化していく
    ll next_position = 0;
    ll rank = -1;
    for (ll i = 59; i >= 0; i--) {
        //i桁目が立っているものを先頭に持っていって下位を消していく
        for (ll j = next_position; j < N; j++) {
            if (A[j] & (1ull << i)) {
                //立っているので先頭へ
                swap(A[j], A[next_position]);
                for (ll k = next_position + 1; k < N; k++) {
                    if (A[k] & (1ull << i)) {
                        A[k] ^= A[next_position];
                    }
                }
                if (next_position++ == 0) {
                    rank = min(i, N - 1);
                }
                break;
            }
        }
    }

    //答えとして立たせることができるかどうかを確認
    ll ans = 0;
    next_position = 0;
    for (ll i = 59; i >= 0; i--) {
        //初めてiが立っているところで制御
        for (ll j = next_position; j < N; j++) {
            if (A[j] & (1ull << i)) {
                //ansに応じてなんやかんやする
                if ((ans & (1ull << i)) == 0) {
                    ans ^= A[j];
                }
                next_position++;
                break;
            }
        }
    }
    ans = ans * 2 + sum;

    cout << ans << endl;
}