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
    int N; std::cin >> N;
    long long cnt(0);
    std::vector<int> L(N);
    for(int i(0); i < N; ++i) std::cin >> L[i];
    std::sort(std::begin(L), std::end(L));
    for(int mid(1), mid_len(N-1); mid < mid_len; ++mid){
        for(int high(mid+1); high < N; ++high){
            int lowlow(L[high] - L[mid] + 1);
            cnt += std::max(0L, std::distance(std::lower_bound(std::begin(L), std::end(L), lowlow), std::begin(L) + mid));
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}
