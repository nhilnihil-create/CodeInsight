#include <bits/stdc++.h>
using namespace std;
void print() {
    cout << endl;
}
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
    cout << head;
    if (sizeof...(tail) != 0)
        cout << " ";
    print(forward<Tail>(tail)...);
}
template <class T>
void print(vector<T> &vec) {
    for (auto &a : vec) {
        cout << a;
        if (&a != &vec.back())
            cout << " ";
    }
    cout << endl;
}
template <class T>
void print(vector<vector<T>> &df) {
    for (auto &vec : df) {
        print(vec);
    }
}
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define xrep(i, a, b) for (int i = int(a); i < int(b); ++i)
#define zrep(i, a, b, c) for (int i = int(a); i < int(b); i+=int(c))
using ll = long long;
const int INF = 1001001001;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> H(N);

    rep(i, N) cin >> H[i];

    vector<vector<int>> to(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    vector<int> OK;
    int ans = 0;
    rep(i, N) {
        int my_height = H[i];
        int cnt = 0;
        for(auto v: to[i]) {
            if(my_height > H[v]) {
                cnt++;
            }
        }
        if(cnt == to[i].size()) {
            ans++;
            OK.push_back(i);
        }
    }

    print(ans);
    return 0;
}
