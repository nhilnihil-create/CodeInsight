#include <iostream>
#include <vector>
using namespace std;

// 入力
int N, M, Q;
vector<long long> a, b, c, d;

// 数列 A のスコアを計算
long long score(const vector<int> &A) {
    long long res = 0;
    for (int i = 0; i < Q; ++i) if (A[b[i]] - A[a[i]] == c[i]) res += d[i];
    return res;
}

// 数列 A を全列挙
long long rec(vector<int> &A) {
    // 終端条件
    if (A.size() == N) return score(A);
    
    // 数列 A の前回要素
    int prev_last = (A.empty() ? 1 : A.back());
    long long res = 0;
    for (int add = prev_last; add <= M; ++add) {
        A.push_back(add);

        // 再帰呼出しながら、スコア最大値を更新
        res = max(res, rec(A)); 
        A.pop_back();
    }
    return res;
}

int main() {
    cin >> N >> M >> Q;
    a.resize(Q); b.resize(Q); c.resize(Q); d.resize(Q);
    for (int q = 0; q < Q; ++q) {
        cin >> a[q] >> b[q] >> c[q] >> d[q];
        --a[q], --b[q];
    }
    vector<int> A;
    cout << rec(A) << endl;
}
