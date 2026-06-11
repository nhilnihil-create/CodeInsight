#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int N, M, Q;
vector<int> a, b, c, d;

// スコア計算関数
int score(vector<int> A) {
    int res = 0;
    rep(i, Q) if (A[b[i]] - A[a[i]] == c[i]) res += d[i];
    return res;
}

int main() {
    cin >> N >> M >> Q;
    a.resize(Q); b.resize(Q); c.resize(Q); d.resize(Q);
    rep(i, Q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--, b[i]--;
    }

    // スタックの初期値は{{1},{2},{3},{4}}
    stack<vector<int>> st;
    rep(i, M){
        vector<int> s = {i+1};
        st.push(s);
    }

    int ans = 0;
    // スタックが空になるまで回し続ける
    while (!st.empty()){
        // スタックの一番上の要素について処理を行う
        vector<int> elem = st.top();
        // 読み取ったら削除しておく
        st.pop();
        // 数列の長さがNであればスコアを計算して最大値を更新していく
        if (elem.size() == N) ans = max(ans, score(elem));
        // 数列の長さがNでなければ要素を追加してスタックにプッシュする
        else {
            repi(i, elem[elem.size()-1], M+1){
                vector<int> elem_new = elem;
                elem_new.push_back(i);
                st.push(elem_new);
            }
        }
    }
    cout << ans << endl;
}