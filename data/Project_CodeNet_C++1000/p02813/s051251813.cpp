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
using ll = long long;
const int INF = 1001001001;

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    vector<int> Q(N);

    rep(i, N) {
        cin >> P[i];
    }
    rep(i, N) {
        cin >> Q[i];
    }
    auto Pd = P;
    auto Qd = Q;

    sort(P.begin(), P.end());
    sort(Q.begin(), Q.end());
    int cnt_a = 0;
    do {
        cnt_a++;
        if(P==Pd) break;
    } while(next_permutation(P.begin(), P.end()));
    int cnt_b = 0;
    do {
        cnt_b++;
        if(Q==Qd) break;;
    } while(next_permutation(Q.begin(), Q.end()));
    print(abs(cnt_a-cnt_b));
    return 0;
}