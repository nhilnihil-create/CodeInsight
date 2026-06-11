// 解答不能.
// 以下のソースコードを勉強する.
// pekempey氏.
// https://atcoder.jp/contests/abc141/submissions/7530985
#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define range(a) a.begin(), a.end()

using namespace std;
using ll = long long;

using vec = bitset<100001>;

bool solve(vector<vec> A, int N, int M){
    int r = 0;
    for(int j = 0; j < M; j++){
        int p = -1;
        for(int i = r; i < N; i++){
            if(A[i][j]){
                p = i;
                break;
            }
        }
        if(p == -1) continue;
        swap(A[r], A[p]);
        for(int i = r + 1; i < N; i++) if(A[i][j]) A[i] ^= A[r];
        r++;
    }
    for(int i = r; i < N; i++) if(A[i][M]) return false;
    return true;
}

int main(){
    int N;
    scanf("%d", &N);
    vector<ll> A(N); rep(i, N) scanf("%lld", &A[i]);
    ll ans = 0;
    vector<int> f, taken;
    repr(i, 60){
        int cnt = 0;
        rep(j, N) if(A[j] >> i & 1) cnt++;
        if(cnt % 2 == 1){
            ans += 1LL << i;
        }else{
            f.push_back(i);
            vector<vec> X(f.size());
            rep(r, f.size()){
                rep(j, N) X[r][j] = A[j] >> f[r] & 1;
            }
            rep(r, taken.size()) X[r][N] = taken[r];
            X[taken.size()][N] = 1;
            if(solve(X, f.size(), N)) taken.push_back(1);
            else                      taken.push_back(0);
        }
    }
    rep(r, f.size()) if(taken[r]) ans += 1LL << f[r] + 1;
    printf("%lld\n", ans);
    return 0;
}