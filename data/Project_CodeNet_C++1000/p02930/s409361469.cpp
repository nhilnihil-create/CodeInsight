#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double Double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// chmax, chmin
template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}


int d = 0;

int u[510][510];

void rec(set<int> s, int d) {
    if (s.size() == 1) return;
    int x = 0;
    set<int> a[2];
    for (auto i : s) {
        a[x % 2].insert(i);
        x++;
        x %= 2;
    }
    for (auto i : a[0]) {
        for (auto j : a[1]) {
            u[i][j] = u[j][i] = d;
        }
    }

    rec(a[0], d + 1);
    rec(a[1], d + 1);

}

void solve(long long N) {
    set<int> A;
    for (int i = 0; i < N; i++) A.insert(i);
    rec(A, 1);
    for (int i = 0; i + 1 < N; i++) {
        for (int j = i + 1; j < N; j++) {
            cout << u[i][j] << " ";
        }
        cout << endl;

    }
}

int main() {
    long long N;
    scanf("%lld", &N);
    solve(N);
    return 0;
}
