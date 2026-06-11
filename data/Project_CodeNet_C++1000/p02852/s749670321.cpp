#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)
#define RREP(i,n) for (int i=(n)-1;i>=0;--i)

using namespace std;

unsigned long long clp(unsigned long long x) {
    x -= 1;
    x = x | (x >>  1);
    x = x | (x >>  2);
    x = x | (x >>  4);
    x = x | (x >>  8);
    x = x | (x >> 16);
    x = x | (x >> 32);
    return x + 1;
}

template <class T>
class segment_tree {
private:
    const size_t n;
    const T UNIT;
    const std::function<T(const T&, const T&)> f;
    std::vector<T> a;
public:
    segment_tree(size_t size, T UNIT, std::function<T(const T&, const T&)> f) : n(clp(size)), UNIT(UNIT), f(f) {
        a.resize(2 * n - 1, UNIT);
    }

    void update(size_t i, const T &x) {
        i += n - 1;
        a[i] = x;
        while (i) {
            i = (i - 1) / 2;
            a[i] = f(a[2 * i + 1], a[2 * i + 2]);
        }
    }

    T query(size_t query_first, size_t query_last, size_t k = 0, size_t node_first = 0, size_t node_last = 0) const {
        if (k == 0) {
            node_last = n;
        }
        if (node_last <= query_first || query_last <= node_first) {
            return UNIT;
        }
        if (query_first <= node_first && node_last <= query_last) {
            return a[k];
        } else {
            size_t node_mid = (node_first + node_last) / 2;
            T vl = query(query_first, query_last, k * 2 + 1, node_first, node_mid);
            T vr = query(query_first, query_last, k * 2 + 2, node_mid, node_last);
            return f(vl, vr);
        }
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    string S;
    cin >> N >> M >> S;
    const int INF = N + 1;

    segment_tree<int> st(M, INF, [](int x, int y) { return min(x, y); });
    st.update(N % M, 0);

    vector<int> pos_seq{N};

    RREP(i, N) {
        if (S[i] == '0') {
            int n_moves = st.query(0, M);
            int n_moves_next;
            if (n_moves == INF) {
                n_moves_next = INF;
            } else {
                n_moves_next = n_moves + 1;
            }
            st.update(i % M, n_moves_next);
            if (n_moves_next == pos_seq.size()) {
                pos_seq.push_back(i);
            }
            else if (n_moves_next == pos_seq.size() - 1) {
                pos_seq[pos_seq.size() - 1] = i;
            }
        } else {
            st.update(i % M, INF);
        }
    }

    if (pos_seq[pos_seq.size() - 1] == 0) {
        RREP(i, pos_seq.size() - 1) {
            int step = pos_seq[i] - pos_seq[i + 1];
            cout << step << '\n';
        }
        cout << flush;
    } else {
        cout << -1 << endl;
    }

    return 0;
}