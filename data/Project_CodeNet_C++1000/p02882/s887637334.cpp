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
#include <unordered_set>

using namespace std;
using Int = long long;

constexpr double EPS = 1e-10;
constexpr long long MOD = 1000000007;

long long mod_pow(long long x, long long n) {
    long long res = 1;
    for (int i = 0;i < 60; i++) {
        if (n >> i & 1) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

long long my_mod_pow(long long x, long long n) {
	long long ret = 1;
	for (; n > 0; n >>= 1, x = x * x % MOD) {
		if (n & 1) {
			ret = ret * x % MOD;
		}
	}
	return ret;
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

int A, B, X;
double pi = 3.141592653589793;

bool check_1(double mid) {
    double empty_water = A * A * tan(pi/2 - mid) * A * (1.0/2);
    return empty_water + X < A * A * B;
}

bool check_2(double mid) {
    return X < A * B * tan(mid) * B * (1.0/2);
}

int main(void) {
    cin >> A >> B >> X;
    double mid, ng, ok;
    ng = 0;
    ok = pi/2;
    if (A*A*B/2.0 <= X) {
        for (int i = 0; i < 100; i++) {
            mid = (ng+ok)/2;
            if (check_1(mid)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        printf("%.12f", 90 - (180 * ok/pi));
    } else {
        for (int i = 0; i < 100; i++) {
            mid = (ng+ok)/2;
            if (check_2(mid)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        printf("%.12f", 90 - (180 * ok/pi));
    }
}
