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

void solve(long long N, std::vector<long long> A) {
    int pos = 0;
    A.push_back(-1e9);

    long long v = 1000;
    while (pos + 1 < A.size()) {
        while (pos + 1 < A.size() && A[pos] >= A[pos + 1]) {
            pos++;
        }
        int mi = A[pos];
        while (pos + 1 < A.size() && A[pos] <= A[pos + 1]) {
            pos++;
        }
        int mx = A[pos];
        v = v % mi + v / mi * mx;
    }
    cout << v << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
