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







//T: int系
template<class T> class BinaryIndexTree{
    int n;
    std::vector<unsigned long long> data;
public:
    BinaryIndexTree(): n(0){}
    BinaryIndexTree(int m): n(m), data(m){}

    void add(int k, T a){
        ++k;
        while(k <= n){
            data[k - 1] += (unsigned long long)a;
            k += k & -k;
        }
    }

    T getSum(int l, int r){
        //[l, r[
        return sum(r) - sum(l);
    }
private:
    unsigned long long sum(int r){
        unsigned long long s(0);
        while(r > 0){
            s += data[r-1];
            r -= r & -r;
        }
        return s;
    }
};

int main(){
    int N, Q; std::cin >> N >> Q;
    BinaryIndexTree<long long> fnt(N);
    {
        int a;
        for(int i(0); i < N; ++i){
            std::cin >> a;
            fnt.add(i, a);
        }
    }
    {
        int op, l, r;
        for(int i(0); i < Q; ++i){
            std::cin >> op >> l >> r;
            if(op) std::cout << fnt.getSum(l, r) << "\n";
            else fnt.add(l, r);
        }
    }
    return 0;
}
