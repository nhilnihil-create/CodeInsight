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
#include <atcoder/segtree>

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







long long op(long long a, long long b){return a+b;}
long long e(){return 0;}

int main(){
    int N, Q; std::cin >> N >> Q;
    atcoder::segtree<long long, op, e> BIT(N);
    {
        int a;
        for(int i(0); i < N; ++i){
            std::cin >> a;
            BIT.set(i, a);
        }
    }
    {
        int op, l, r;
        for(int i(0); i < Q; ++i){
            std::cin >> op >> l >> r;
            if(op) std::cout << BIT.prod(l, r) << "\n";
            else BIT.set(l, BIT.get(l) + r);
        }
    }
    return 0;
}
