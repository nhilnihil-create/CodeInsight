#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define rep3(i, n) for(int i = n-1; i >= 0; i--)
#define rep4(i, x, n) for(int i = x; i > n; i--)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e15;

int main(){
    int N;
    cin >> N;
    int A[N];
    rep(i, N) cin >> A[i];
    int num[N+1];
    fill_n(num, N+1, 0);
    rep(i, N) num[A[i]]++;
    int cnt[N+1];
    fill_n(cnt, N+1, 0);
    rep2(i, 1, N+1) cnt[num[i]]++;
    int dp[N+1];
    int sum = N;
    dp[0] = 0;
    rep2(i, 1, N+1){
        sum -= cnt[i-1];
        dp[i] = dp[i-1] + sum;
    }
    int S[N+1];
    S[0] = N;
    S[N+1] = 0;
    rep2(i, 1, N+1) S[i] = dp[i]/i;
    rep3(i, N+1){
        rep2(j, S[i+1]+1, S[i]+1) cout << i << endl;
    }
}