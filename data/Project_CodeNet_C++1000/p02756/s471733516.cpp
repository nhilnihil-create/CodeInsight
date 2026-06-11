#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
#define debug(x) cerr << #x << ": " << x << '\n'
using namespace std;
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

using ll = long long;
using ull = unsigned long long;
const int INF = 1e9;
// const int MOD = 1e9 + 7;

int main() {
    string S;
    cin >> S;
    int Q;
    cin >> Q;

    int N = (int)S.size();
    deque<char> deq;
    for (int i = 0; i < N; i++) {
        deq.push_back(S[i]);
    }

    int ord = 0;
    for (int q = 0; q < Q; q++) {
        int T;
        cin >> T;
        if (T == 1) {
            ord ^= 1;
        } else if (T == 2) {
            int F;
            char C;
            cin >> F >> C;
            F--;
            if ((ord ^ F) == 0) {
                deq.push_front(C);
            } else {
                deq.push_back(C);
            }
        }
    }

    if (ord == 0) {
        while (!deq.empty()) {
            char c = deq.front();
            deq.pop_front();
            cout << c;
        }
    } else if (ord == 1) {
        while (!deq.empty()) {
            char c = deq.back();
            deq.pop_back();
            cout << c;
        }
    }
    cout << endl;
}
