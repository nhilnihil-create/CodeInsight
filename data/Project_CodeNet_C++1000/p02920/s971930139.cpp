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
// 1次元 vector
template <class T>
ostream &operator<<(ostream &s, vector<T> vec) {
    for (int i = 0; i < (int)vec.size(); ++i) {
        if (i > 0) {
            s << " ";
        }
        s << vec[i];
    }
    return s << endl;
}
template <class T>  // 2次元 vector
ostream &operator<<(ostream &s, vector<vector<T>> vec2) {
    for (int i = 0; i < (int)vec2.size(); ++i) {
        s << vec2[i];
    }
    return s;
}

int main() {
    int N;
    cin >> N;
    vector<int> S(1 << N), T;
    priority_queue<int> que;
    for (int i = 0; i < (1 << N); i++) {
        cin >> S.at(i);
        que.push(S[i]);
    }
    sort(S.begin(), S.end(), greater<int>());

    T.push_back(que.top());
    que.pop();
    for (int i = 0; i < N; i++) {
        //cerr << T;
        vector<int> s;
        for (int j = 0; j < (1 << i); j++) {
            while (!que.empty()) {
                int now = que.top();
                if (now >= T[j]) {
                    s.push_back(now);
                    que.pop();
                } else {
                    T.push_back(now);
                    break;
                }
            }
            if (que.empty()) {
                cout << "No\n";
                return 0;
            } else {
                que.pop();
            }
        }
        sort(T.begin(), T.end(), greater<int>());
        for (auto a : s) {
            que.push(a);
        }
    }
    cout << "Yes\n";
}
