#include <bits/stdc++.h>
#define INF 1e9
#define INFLL 1ull<<60u
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
typedef long long ll;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N),B(N),C(N-1);
    REP(i,N) cin >> A[i];
    REP(i,N) cin >> B[i];
    REP(i,N-1) cin >> C[i];

    ll ans = 0;
    REP(i,N) {
        if(i != 0) {
            if (A[i] - A[i-1] == 1) ans += C[A[i-1]-1];
        }
        ans += B[A[i]-1];
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}