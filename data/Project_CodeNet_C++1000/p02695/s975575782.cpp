#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int N, M, Q;
vector<ll> a, b, c, d;

ll score(vector<int> A) {
    ll res = 0;
    rep(i, Q) if (A[b[i]] - A[a[i]] == c[i]) res += d[i];
    return res;
}

ll dfs(vector<int> A) {
    if (A.size() == N) {
        return score(A);
    }

    ll res = 0;
    int last = 0;
    if (!A.empty()) last = A.back();
    repi(i, last, M){
        A.push_back(i);
        res = max(res, dfs(A)); // 再帰呼出しながら、スコア最大値を更新
        A.pop_back();
    }
    return res;
}

int main() {
    cin >> N >> M >> Q;
    a.resize(Q); b.resize(Q); c.resize(Q); d.resize(Q);
    rep(i, Q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--, b[i]--;
    }
    vector<int> A;
    cout << dfs(A) << endl;
}