#include <cmath>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <chrono>
#include <random>
#include <tuple>
#include <utility>
#include <fstream>
#include <complex>
#include <cstdint>
#define _USE_CMATH_DEFINES

const long INF = (1l << 30);
const long LINF = (1l << 60); //1.15*10^18

void over_modify(const long i, std::vector<long>& dp, const std::string s){
    for(long j = i+1; s[j] == '1'; j++){
        dp[j] = dp[i];
    }
}

std::vector<long> solve(long n, long m, std::string s){
    std::vector<long> dp(n+1, LINF);
    dp[n] = 0;
    for(long i = n-1; i >= 0; i--){
        if(i+m > n && s[i] == '0'){
            dp[i] = 1;
            over_modify(i, dp, s);
        }else if(s[i] == '0'){
            dp[i] = dp[i+m]+1;
            over_modify(i, dp, s);
        }
    }

    /*
    for(int i = 0; i < dp.size(); i++){
        printf(" %ld", dp[i]);
    }
    printf("\n");
    //*/

    if(dp[0] >= LINF){
        return std::vector<long>(1, -1);
    }
    std::vector<long> ans(dp[0]);
    long index = 0;
    long vis = 0;
    for(long i = 0; i <= n; i++){
        if(s[i] == '0' && dp[i] == dp[vis] - 1){
            ans[index] = i - vis;
            vis = i;
            index++;
        }
    }
    return ans;
}

int main(){
    long n, m;
    scanf("%ld%ld", &n, &m);
    std::string s;
    std::cin >> s;
    std::vector<long> ans = solve(n, m, s);
    for(int i = 0; i < ans.size(); i++){
        printf("%ld ", ans[i]);
    }
    printf("\n");
}
