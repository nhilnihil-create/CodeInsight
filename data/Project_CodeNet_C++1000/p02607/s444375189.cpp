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
    vector<int> A;
    A.push_back(INF);
    rep(i, N) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    int cnt = 0;
    xrep(i, 1, N+1) {
        if(i%2==1 && A[i]%2==1) {
            cnt++;
        }
    }
    print(cnt);

    return 0;
}