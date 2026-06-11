#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long LL;
template <typename F, typename S> std::ostream& operator<<(ostream& os, const pair<F,S>& p) {
    os << "(" << p.first << "," << p.second << ")"; return os; }
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "["; for(const T& a: v){ os << a << ", "; } os << "]"; return os; }
template <typename K, typename V> ostream& operator<<(ostream& os, const map<K,V>& m) {
    os << "{"; for(const auto& p: m){ os << p.first <<":"<< p.second << ", "; } os << "}"; return os; }



int main(){
    LL n, t;
    cin >> n >> t;
    vector<vector<LL>> dp(n+1, vector<LL>(t+1));
    vector<pair<LL,LL>> dish(n);
    for(LL i = 0; i < n; ++i){
        LL a, b;
        cin >> dish[i].first >> dish[i].second;
    }
    sort(dish.begin(), dish.end());

    LL ans = 0;
    for(LL i = 0; i < n; ++i){
        for(LL j = 0; j < t; ++j){
            LL t2 = min(t, j + dish[i].first);
            dp[i+1][t2] = max(dp[i+1][t2], dp[i][j] + dish[i].second);
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }
        dp[i+1][t] = max(dp[i+1][t], dp[i][t]);
    }
    cout << dp[n][t] << endl;
    return 0;
}

