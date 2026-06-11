#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N, T;
    cin >> N >> T;
    vector<pair<int,int>> dish(N);
    REP(i, N) cin >> dish[i].first >> dish[i].second;

    if(T == 1){
        int ans = 0;
        REP(i, N) ans = max(ans, dish[i].second);
        cout << ans << endl;
        return 0;
    }
    
    sort(dish.begin(), dish.end());

    int ans = 0;
    vector<int> dp(T, 0);
    REP(i, N){
        int A = dish[i].first;
        int B = dish[i].second;
        ans = max(ans, dp[T-1]+B);
        for(int j = T-1; j >= A; --j) dp[j] = max(dp[j], dp[j-A]+B);
        // REP(i, T) cout << dp[i] << " ";
        // cout << endl;
    }
    cout << ans << endl;

    return 0;
}