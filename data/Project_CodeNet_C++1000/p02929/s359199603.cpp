#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <functional>
#include <cctype>
#include <list>
#include <limits>
#include <cassert>
#include <random>
#include <time.h>
//#include <boost/multiprecision/cpp_int.hpp>



using namespace std;
using Int = long long;
//using namespace boost::multiprecision;

const double EPS = 1e-10;
long long const MOD = 1000000007;

long long mod_pow(long long x, long long n) {
    long long res = 1;
    for (int i = 0;i < 60; i++) {
        if (n >> i & 1) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

template<typename T>
T gcd(T a, T b) {
    return b != 0 ? gcd(b, a % b) : a;
}

template<typename T>
T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

void fastInput() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main(void) {
    int N; cin >> N;
    N *= 2;
    string S; cin >> S;

    int parity = 1;
    Int ans = 1;
    for (int i = 1; i < N; i++) {
        char crt = S[i];
        if (crt == 'B') {
            if (parity % 2) {
                ans *= parity;
                ans %= MOD;
                parity--;
                if (parity < 0) break;
            }
            else parity++;
        }
        if (crt == 'W') {
            if (parity % 2) parity++;
            else {
                ans *= parity;
                ans %= MOD;
                parity--;
                if (parity < 0) break;
            }
        }
    }

    N /= 2;
    Int weight = 1;
    for (int i = 1; i <= N; i++) {
        weight *= i;
        weight %= MOD;
    }

    if (parity == 0) {
        cout << ans*weight%MOD << endl;
    } else {
        cout << 0 << endl;
    }
    
}