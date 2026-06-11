#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define rep(i, n) for(int i=0; i<n; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define V(T) vector<T>
typedef pair<int, int> P;
typedef pair<P, P> PP;
typedef vector<int> vi;
typedef vector<vi> vvi;
int max(int a, int b) {if(b>a) return b; else return a;}
int min(int a, int b) {if(b<a) return b; else return a;}


signed main() {
    int N, T;
    cin >> N >> T;

    V(P) AB(N);
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        AB[i] = P(a, b);
    }
    SORT(AB);

    /*vvi dp(N+1, vi(T+1, 0));

    rep(i, N) {
        for(int j=T-1; j>=0; j--) {
            if(j+AB[i].fi>=T) {
                dp[i+1][T] = max(dp[i][T], dp[i][j]+AB[i].se);
            } else {
                dp[i+1][j+AB[i].fi] = max(dp[i][j+AB[i].fi], dp[i][j]+AB[i].se);
            }
        }
    }

    cout << dp[N][T] << endl;*/

    vi dp(T+1, 0);
    rep(i, N) {
        for(int j=T-1; j>=0; j--) {
            int t = min(j+AB[i].fi, T);
            dp[t] = max(dp[t], dp[j]+AB[i].se);
        }
    }

    cout << dp[T] << endl;

    return 0;
}