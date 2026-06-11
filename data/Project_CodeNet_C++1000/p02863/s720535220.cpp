#define _USE_MATH_DEFINES
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

const int MOD = 1'000'000'007; 
const int INF = 1'000'000'000; //1e9
const int NIL = -1;
const long long LINF = 1'000'000'000'000'000'000; // 1e18
const long double EPS = 1E-10;

template<class T, class S> inline bool chmax(T &a, const S &b){
    if(a < b){
        a = b; return true;
    }
    return false;
}
template<class T, class S> inline bool chmin(T &a, const S &b){
    if(b < a){
        a = b; return true;
    }
    return false;
}





int main(){
    int N, T; std::cin >> N >> T;
    std::vector<std::pair<int, int>> AB(N);
    for(int i(0); i < N; ++i){
        std::cin >> AB[i].first >> AB[i].second;
    }
    std::sort(std::begin(AB), std::end(AB));
    int ans(0);
    //dp[i][j] := (1からi 1o)でj分以内に完食 おいしさの合計max
    std::vector<std::vector<int>> dp(N+1, std::vector<int>(T, 0));
    for(int i(1); i <= N; ++i){
        for(int j(0); j < T; ++j){
            dp[i][j] = dp[i-1][j];
            chmax(ans, dp[i][j] + AB[i-1].second);
            if(j >= AB[i-1].first){
                chmax(dp[i][j], dp[i-1][j-AB[i-1].first] + AB[i-1].second);
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
