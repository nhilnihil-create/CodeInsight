#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
using ll = long long int;
using P = pair<ll, ll>;


const int N_MAX = 3005;
const int T_MAX = 3005;
const int A_MAX = 3005;
int n, t;
vector<P> Dish;
ll dp[N_MAX][T_MAX+A_MAX];

int main(){
    cin >> n >> t;
    for(int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        Dish.emplace_back(a, b);
    }
    sort(Dish.begin(), Dish.end());

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < t+A_MAX; j++){
            ll A = Dish[i-1].first, B = Dish[i-1].second;
            if (j-A < t && j-A >= 0) dp[i][j] = max(dp[i-1][j], dp[i-1][j-A]+B);
            else dp[i][j] = dp[i-1][j];
        }
    }
    ll ans = 0;
    for(int i = 1; i <= t+A_MAX; i++){
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}