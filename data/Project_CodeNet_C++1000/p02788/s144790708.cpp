#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

struct LazySegTree {
  private:
    int n;
    vector<ll> node, lazy;

  public:
    LazySegTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1;
        while(n < sz)
            n *= 2;
        node.resize(2 * n - 1);
        lazy.resize(2 * n - 1, 0);

        for(int i = 0; i < sz; i++)
            node[i + n - 1] = v[i];
        for(int i = n - 2; i >= 0; i--)
            node[i] = node[i * 2 + 1] + node[i * 2 + 2];
    }

    // k番目のノードについて遅延評価
    void eval(int k, int l, int r) {
        // 遅延配列を見て空でなかったら値を伝播
        if(lazy[k] != 0) {
            node[k] += lazy[k];
            // 最下段かどうかチェック
            // 伝播
            if(r - l > 1) {
                lazy[2 * k + 1] += lazy[k] / 2;
                lazy[2 * k + 2] += lazy[k] / 2;
            }
        }

        // 伝播の終了
        lazy[k] = 0;
    }

    ll at(int k) { return getsum(k, k + 1); }

    // [a,b)区間加算
    void add(int a, int b, ll x, int k = 0, int l = 0, int r = -1) {
        if(r < 0)
            r = n;
        // まず評価
        eval(k, l, r);
        // 範囲外なら何もしない
        if(b <= l || r <= a)
            return;

        // 完全に被覆 遅延配列に値を入れ評価
        if(a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        // そうでないとき 子コードの値を再帰的に計算して計算済みの値をもってくる
        else {
            add(a, b, x, 2 * k + 1, l, (l + r) / 2);
            add(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = node[2 * k + 1] + node[2 * k] + 2;
        }
    }

    // [a,b)区間取得
    ll getsum(int a, int b, int k = 0, int l = 0, int r = -1) {
        if(r < 0)
            r = n;
        if(b <= l || r <= a)
            return 0;

        // まず評価
        eval(k, l, r);
        if(a <= l && r <= b)
            return node[k];
        ll vl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = getsum(a, b, 2 * k + 2, (l + r) / 2, r);
        return vl + vr;
    }
};

int main() {
    int N;
    ll D, A;
    cin >> N >> D >> A;
    vector<pll> monstor(N);
    rep(i, N) {
        ll x, h;
        cin >> x >> h;
        monstor[i] = MP(x, h);
    }
    sort(All(monstor));

    vector<ll> H(N);
    rep(i, N) H[i] = monstor[i].second;

    LazySegTree Segtree(H);

    int right = 0;
    int len = 0;
    ll res = 0;
    for(int left = 0; left < N; left++) {
        if(Segtree.at(left) < 0)
            continue;
        if(right < left)
            right = left;
        while(right < N &&
              monstor[right].first - monstor[left].first <= 2 * D) {
            right++;
        }
        ll rest = Segtree.at(left);
        ll cnt = rest / A + !!(rest % A);
        res += cnt;
        Segtree.add(left, right, -A * cnt);
    }
    cout << res << endl;

    return 0;
}