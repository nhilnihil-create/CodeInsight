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
    int N; long long K, sum(0);
    std::cin >> N >> K;
    std::vector<int> A(N), F(N);
    for(int i(0); i < N; ++i){
        std::cin >> A[i];
        sum += A[i];
    }
    if(sum <= K){
        std::cout << 0 << std::endl;
        return 0;
    }
    for(int i(0); i < N; ++i) std::cin >> F[i];

    std::sort(std::begin(A), std::end(A));
    std::sort(std::rbegin(F), std::rend(F));

    long long mx(0);
    for(int i(0); i < N; ++i) chmax(mx, (long long)A[i] * F[i]);
    long long ng(0), ok(mx);
    while(std::abs(ok-ng) > 1){
        long long mid((ng+ok)/2), difSum(0);
        for(int i(0); i < N; ++i){
            difSum += std::max(0LL, A[i] - mid/F[i]);
        }
        if(difSum <= K) ok = mid;
        else ng = mid;
    }
    std::cout << ok << std::endl;
    return 0;
}
