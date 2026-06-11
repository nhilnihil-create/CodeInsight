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
// #include <boost/multiprecision/cpp_int.hpp>



using namespace std;
using Int = long long;
// using namespace boost::multiprecision;

const double EPS = 1e-10;
long long const MOD = 1000000007;

typedef vector<int> vec;
typedef vector<vec> mat;

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

int main(void) {
    Int T1, T2, A1, A2, B1, B2;
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
    Int C1 = (A1 - B1) * T1;
    Int C2 = (A2 - B2) * T2;

    if (C1 + C2 == 0) {
        cout << "infinity" << endl;
    } else if (C1 < 0 && C1 + C2 < 0) {
        cout << 0 << endl;
    } else if (C1 > 0 && C1 + C2 > 0) {
        cout << 0 << endl;
    } else {
        Int D1 = abs(C1);
        Int D2 = abs(C1 + C2);
        Int ans = 1;
        ans += D1 / D2 * 2;
        if (D1 % D2 == 0) ans--;
        cout << ans << endl;
    }
    return 0;
}