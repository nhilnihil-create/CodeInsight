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
    vector<int> W(N);
    rep(i, N) cin >> W[i];

    int min_v = INF;
    rep(i, N) {
        int T1 = 0; 
        int T2 = 0;
        rep(j, N) {
            if(i<j) T1 += W[j];
            else T2 += W[j];
        }
        min_v = min(min_v, abs(T1-T2));
    }
    print(min_v);
    return 0;
}