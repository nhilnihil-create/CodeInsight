#include <bits/stdc++.h>
using namespace std;

#define SZ(x) (int)(x).size()
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i, a, b) for (int i=a;i>=b;--i)

const int MX_N = 2e5+5;

int N, A[MX_N], B[MX_N];
queue<int> q;

inline int prv(int i) { return i == 1 ? N : i-1; }
inline int nxt(int i) { return i == N ? 1 : i+1; }
inline bool bad(int i) { return B[i] - (B[prv(i)] + B[nxt(i)]) >= A[i]; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    FOR(i,1,N){
        cin >> A[i];
    }
    FOR(i,1,N){
        cin >> B[i];
    }
    FOR(i,1,N){
        if (bad(i)) q.push(i);
    }
    long long op = 0;
    while (!q.empty()) {
        int i = q.front(); q.pop();
        int x = prv(i), y = nxt(i);
        int cur = (B[i]-A[i])/(B[x]+B[y]);
        op += cur;
        B[i] -= cur*(B[x]+B[y]);
        if (bad(x)) q.push(x);
        if (bad(y)) q.push(y);
    }

    bool good = 1;
    FOR(i,1,N) if (A[i] != B[i]) { good = 0; break; }
    if (good) cout << op;
    else cout << -1;
}

