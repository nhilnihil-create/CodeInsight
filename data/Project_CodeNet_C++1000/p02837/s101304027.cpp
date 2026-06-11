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
    //info[i][j]: i人目が正直の時 j人目は (-1:不明 1:正直 0:不親切)
    std::vector<std::vector<int>> info(N, std::vector<int>(N, -1));
    {
        int A, x, y;
        for(int i(0); i < N; ++i){
            std::cin >> A;
            info[i][i] = 1;
            for(int j(0); j < A; ++j){
                std::cin >> x >> y;
                --x;
                info[i][x] = y;
            }
        }
    }
    int ans(0);
    for(int i(0), i_len(1 << N); i < i_len; ++i){
        std::vector<int> fact(N); 
        int honest(0);
        for(int j(0); j < N; ++j){
            fact[j] = ((i >> j) & 1);
            if(fact[j]) ++honest;
        }

        bool okay(true);
        for(int j(0); j < N; ++j){
            if(!fact[j]) continue;
            for(int k(0); k < N; ++k){
                if(info[j][k] == -1) continue;

                if(info[j][k] != fact[k]){
                    okay = false; break;
                }
            }
            if(!okay) break;
        }
        if(okay) chmax(ans, honest);
    }
    std::cout << ans << std::endl;
    return 0;
}
