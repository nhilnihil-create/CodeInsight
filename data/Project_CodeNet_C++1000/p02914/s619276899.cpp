#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll>A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // 関係ない桁は総和が0か奇数
    // 総和0はガウスの消去法に影響しないので総和が奇数の桁を0にする
    ll mask = 0; // 和が奇数の桁が1
    for (int i = 0; i < N; ++i) {
        mask ^= A[i];
    }
    for (int i = 0; i < N; ++i) {
        A[i] &= ~mask;
    }

    // ガウスの消去法でAの部分集合のxorを最大化
    int fixed = 0;
    for (int i = 59; i >= 0; --i) {
        queue<int> que;
        for (int j = fixed; j < N; ++j) {
            if(__builtin_clzll(A[j]) == 63 - i) que.push(j);
        }
        if(que.empty()) continue;
        int top = que.front();
        que.pop();
        // 入れ替え対象は自分自身かqueueに入らないもの
        ll temp = A[fixed];
        A[fixed] = A[top];
        A[top] = temp;
        while (! que.empty()){
            A[que.front()] ^= A[fixed];
            que.pop();
        }
        fixed++;
    }
    ll res = 0;
    for (int i = 0; i < N; ++i) {
        res = max(res, res ^ A[i]);
    }
    res *= 2;
    res += mask;
    cout << res;
    return 0;
}