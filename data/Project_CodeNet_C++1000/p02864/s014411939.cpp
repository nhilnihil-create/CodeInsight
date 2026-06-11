#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<int, int> i_i;
ll INF = 1e12+10;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
vector<pair<ll, ll> > pairs;

const ll MAX = 10000000000 * 300 + 10;
ll dp[310][310];
int main()
{
    ll N, K, tmp;
    cin >> N >> K;
    vector<ll> H(N + 2);
    rep(i, N)cin >> H[i + 1];
    H[0] = H[N + 1] = 0;
    
    //rep(i, N)cout << H[i + 1]  << endl;
    for (int i = 1; i <= N; i++){
        dp[0][i] = MAX;
        //dp[i][0] = 0;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            tmp = MAX;
            for (int i0 = 0; i0 < i; i0++){
                if (j - 1 == 0){
                    tmp = H[i];
                } else {
                    tmp = min(tmp, dp[i0][j - 1] + max(0LL, H[i] - H[i0]));
                }
                //fprintf(stderr, "i0 = %d, tmp = %d\n", i0, tmp);
            }
            dp[i][j] = tmp;
            //cout << i << " " << j << " " << tmp << endl;
            //fprintf(stderr, "dp[%d][%d] = %Ld\n", i, j, tmp);
        }
    }
    ll ans = MAX;
    for (int i = 1; i <= N; i++){
        ans = min(ans, dp[i][N - K]);
    }
    cout << ans;
    return 0;
}
