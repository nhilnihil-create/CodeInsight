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


LL paintCount(LL n, vector<LL>& h, LL i, LL j){
    LL cnt = 0;
    LL left = 0;
    if(i > 0) left = h[i-1];
    for(LL cur = i; cur <= j; ++cur){
        cnt += max(0LL, h[cur] - left);
        left = h[cur];
    }
    return cnt;
}

LL paintCount2(LL n, vector<LL>& h, LL i, LL j){
    LL left = 0;
    if(i > 0) left = h[i-1];
    return max(0LL, h[j] - left);
}

int main(){
    LL n, k;
    cin >> n >> k;
    vector<LL> h(n+1);
    for(LL i = 0; i < n; ++i){
        cin >> h[i];
    }
    vector<vector<LL>> dp(n+2, vector<LL>(k+1));
    for(LL i = 0; i <= n; ++i){
        for(LL j = i; j <= n; ++j){
            for(LL b = 0; b <= k; ++b){
                dp[j+1][b] = max(dp[j+1][b], dp[i][b]);
            }
        }
        for(LL j = i+1; j <= n; ++j){
            LL cnt = paintCount(n, h, i, j) - paintCount2(n, h, i, j);
            //cerr << i << " " << j << " " << cnt << endl;
            for(LL b = 0; b < k; ++b){
                if(b+j-i > k) continue;
                dp[j+1][b+j-i] = max(dp[j+1][b+j-i], dp[i][b] + cnt);
            }
        }
    }
    for(auto row: dp){
        //cerr << row << endl;
    }
    LL total = paintCount(n, h, 0, n);
    //cerr << "total=" << total << endl;
    cout << total - dp[n+1][k] << endl;
    return 0;
}

