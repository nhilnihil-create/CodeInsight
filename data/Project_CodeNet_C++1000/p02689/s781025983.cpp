#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;
const ll INF = 9e18;

void print() { cout << endl; }
template <typename Head, typename... Tail>
void print(Head head, Tail... tail) {
    int size = sizeof...(Tail);
    cout << head;
    if (size > 0) {
        cout << " ";
    }
    print(tail...);
}

void print0() {}
template <typename Head, typename... Tail>
void print0(Head head, Tail... tail) {
    cout << head;
    print0(tail...);
}

class iunionfind {
   public:
    // 連続するuintにのみ使える。vectorであるため定数時間がとれる。
    // 基本的にこれだけあればよい。任意の構造体を扱うときは、IDと構造体のマッピングをとるvectorを別途用意する。
    // libs-test.cppの iuf_map あたりを検索。
    vector<ull> partition;
    vector<ull> rank;

    iunionfind(ull n) {
        partition.resize(n);
        rank.resize(n);
        for (ull x = 0; x < n; x++) {
            partition[x] = x;
            rank[x] = 0;
        }
    }
    ull find(ull x) {
        if (partition[x] == x) {
            return x;
        } else {
            partition[x] = find(partition[x]);
            return partition[x];
        }
    }
    void unite(ull x, ull y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (rank[x] < rank[y]) {
            partition[x] = y;
        } else {
            partition[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }
    bool same(ull x, ull y) {
        return find(x) == find(y);
    }
};

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> H(N);
    auto uf = iunionfind(N);

    for (ll i = 0; i < N; i++) {
        cin >> H[i];
    }
    vector<vector<ll>> near(N);
    for (ll i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        near[a].push_back(b);
        near[b].push_back(a);
    }
    ll result = 0;
    for (ll i = 0; i < N; i++) {
        ll h = H[i];
        bool highest = true;
        for (auto ne : near[i]) {
            ll hne = H[ne];
            if (hne >= h) {
                highest = false;
            }
        }
        if (highest) {
            result++;
        }
    }
    print(result);
    // map<ll, pair<ll, ll>> topcnt;
    // for (ll i = 0; i < N; i++) {
    //     ll un = uf.find(i);
    //     ll h = H[i];
    //     if (topcnt.count(un)) {
    //         ll hcur = topcnt[un].first;
    //         if (h > hcur) {
    //             topcnt[un] = make_pair(h, 1);
    //         } else if (h == hcur) {
    //             topcnt[un].second++;
    //         }
    //     } else {
    //         topcnt[un] = make_pair(h, 1);
    //     }
    // }

    // ll result = 0;
    // for (auto t : topcnt) {
    //     if (t.second.second == 1) {
    //         result++;
    //     }
    // }
    // print(result);
}
