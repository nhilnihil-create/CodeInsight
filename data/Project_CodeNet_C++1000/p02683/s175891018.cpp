#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

int N, M, X;
int A[15][15], under[15];

int main() {
    cin >> N >> M >> X;
    vector<int> C(N);
    rep(i,N) {
        cin >> C[i];
        rep(j, M) cin >> A[i][j];
    }
    int res = INF;
    rep(c, 1 << N) {
        rep(j,M) under[j] = 0;
        int cur = 0;
        rep(i,N) {
            if( (c>>i)&1 ) {
                cur += C[i];
                rep(j,M) under[j] += A[i][j];
            } 
        }
        int count = 0;
        rep(j,M) if (under[j] >= X) count++;
        if (count == M) chmin(res, cur);
    }
    if (res == INF) cout << "-1" << endl;
    else cout << res << endl;
}
