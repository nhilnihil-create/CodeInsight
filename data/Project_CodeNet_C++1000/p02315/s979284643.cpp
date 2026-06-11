#include<algorithm>
#include<climits>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<utility>
#include<vector>

#define lint long long
#define REP(i, x, n) for(int i = x ; i < n ; i++)
#define rep(i, n) REP(i, 0, n)
#define repr(i, n) for(int i = n - 1 ; i >= 0 ; i--)
#define SORT(c) sort((c).begin(), (c).end())
#define SORT_INV(c) sort((c).begin(), (c).end(), greater<int>())
#define IINF INT_MAX
#define LLINF LLONG_MAX

using namespace std;

int main(){
    int N, W;
    cin >> N >> W;
    vector< pair<int, int> > goods(N);
    rep(i, N){
        int v, w;
        cin >> v >> w;
        goods[i] = make_pair(v, w);
    }
    int dp[110][10010]; //dp[i][j] i番目まで、重さj以下で選んだときの価値の最大値
    rep(i, N+1){
        dp[i][0] = 0;
    }
    REP(i, 1, N+1){
        rep(j, W+1){
            if(j >= goods[i-1].second){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-goods[i-1].second] + goods[i-1].first);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[N][W] << endl;
    return 0;
}
