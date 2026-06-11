#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;
typedef complex<double> xy_t;

const lint mod = 1e9 + 7;


void Gauss(vector<vector<int>> &A, int n){
    int cur = 0;
    rep(j, 60){
        if(cur == n) break;
        if(A[cur][j] == 0){
            For(i, cur+1, n)if(A[i][j]){
                rep(k, 60) A[cur][k] ^= A[i][k];
                break;
            }
        }
        if(A[cur][j] == 0) continue;
        rep(i, n)if(i != cur && A[i][j]){
            rep(k, 60) A[i][k] ^= A[cur][k];
        }
        ++cur;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    lint a[n], x;
    vector<vector<int>> A = vector<vector<int>>(n, vector<int>(60, 0));
    x = 0;
    rep(i, n){
        scanf("%lld", &a[i]);
        x ^= a[i];
        rep(j, 60) A[i][j] = (a[i] >> (59-j)) & 1;
    }

    lint ans = 0;
    rep(j, 60){
        lint t = (x >> (59-j)) & 1;
        ans += t << (59-j);
        rep(i, n)if(t) A[i][j] = 0;
    }

    Gauss(A, n);

    rep(j, 60){
        lint tmp = 0;
        rep(i, n) tmp ^= A[i][j];
        ans += tmp << (60-j);
    }

    printf("%lld\n", ans);
}