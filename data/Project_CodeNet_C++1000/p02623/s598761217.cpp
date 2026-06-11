#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n); ++i)
typedef long long ll;

const int mod = 1e9+7;
const int INF = 2000000;
const double PI = acos(-1.0);


int main() {
    
    int N, M, K;
    cin >> N >> M >> K;
    int A[N], B[M];

    rep(i,N) cin >> A[i];
    rep(i,M) cin >> B[i];

    ll an[N+1],am[M+1];
    an[0] = 0, am[0] = 0;
    for(int i = 0; i < N; i++) an[i+1] = an[i] + A[i];
    for(int i = 0; i < M; i++) am[i+1] = am[i] + B[i];
    int ans = 0;
    for(int i = 0; i <= N; i++) {
        ll tmp = K - an[i];
        if(tmp < 0) break;
        int j = upper_bound(am, am+M+1, tmp) - am - 1;
        ans = max(ans, i+j);
    }
    cout << ans << endl;
}
