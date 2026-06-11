#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

int N, M, K;
int a[200005], b[200005];
ll tota[200005], totb[200005]; 

int main() {
    cin >> N >> M >> K;
    rep(i,N) cin >> a[i];
    rep(i,M) cin >> b[i];
    rep(i,N) {
        tota[i+1] = tota[i] + a[i];
    }
    rep(i,M) {
        totb[i+1] = totb[i] + b[i];
    }
    int res = 0;
    int nj = M;
    rep(ni, N+1) {
        while(nj >= 0 && totb[nj]  + tota[ni] > K) nj--;
        if(0 <= nj) chmax(res, ni + nj);
    }
    cout << res << endl;
    return 0;
}
