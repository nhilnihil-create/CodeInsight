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
const int INF = 100100100;


int main() {
    int N, K ,Q;
    cin >> N >> K >> Q;
    vector<int> A(Q);
    rep(i, Q) {
        int a;
        cin >> a;
        a--;
        A[i] = a;
    }

    vector<int> B(N, K-Q);
    
    for(auto a: A) {
        B[a]++;
    }

    for(auto b: B) {
        if(b<=0) {
            print("No");
        }
        else {
            print("Yes");
        }
    }
    return 0;
}