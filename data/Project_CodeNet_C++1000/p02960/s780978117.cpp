#define _USE_MATH_DEFIMES
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
#include <random>
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
    std::string S; std::cin >> S;
    int n(S.length());
    //dp[i][m] := 先頭i桁で余りmの数
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(13, 0));
    dp[0][0] = 1;

    for(int i(0); i < n; ++i){
        int c(S[i] == '?' ? NIL : S[i] - '0');

        for(int j(0); j < 10; ++j){
            if(c != NIL && c != j) continue;

            for(int k = 0; k < 13; ++k){
                (dp[i+1][(k * 10 + j) % 13] += dp[i][k]) %= MOD;
            }
        }

    }

    std::cout << dp[n][5] << std::endl;
    return 0;
}
