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
    int A, B, C, K;
    cin >> A >> B >> C >> K;
    bool flag = false;
    rep(k1, K+1) {
        rep(k2, K+1) {
            rep(k3, K+1) {
                if(k1+k2+k3<=K) {
                    int red = A*1<<k1;
                    int green = B*1<<k2;
                    int blue = C*1<<k3;
                    if(red<green && green<blue) {
                        flag = true;
                    }
                }
            }
        }
    }
    if(flag) {
        print("Yes");
    } else {
        print("No");
    }
    
    return 0;
}