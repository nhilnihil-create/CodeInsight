#include"bits/stdc++.h"
#include<unordered_set>
#include<unordered_map>
#include<random>
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9+7);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(int)(n); (i)++)
int dx[4]={ 1,0,-1,0 };
int dy[4]={ 0,1,0,-1 };

// 最後に注文する料理は注文する料理の中で最も所要時間が長いものにするのが最適

int N, T, A[3000], B[3000];
pair<int, int> a[3000];

int dp[3001][3001];
int solve(int n, int t){
    if(n == N) return 0;
    if(t >= T) return 0;
    if(dp[n][t] != -1) return dp[n][t];
    return dp[n][t] = max(solve(n+1, t), solve(n+1, t+a[n].first) + a[n].second);
}

signed main(){
    cin >> N >> T;
    rep(i, N){
        cin >> A[i] >> B[i];
        a[i] ={ A[i], B[i] };
    }
    sort(a, a+N);
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << endl;
}