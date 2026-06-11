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
    int N, M; cin >> N >> M;
    string S; cin >> S;
    reverse(S.begin(), S.end());
    int crt = 0;
    int next = crt;
    vector<int> ans;
    for (int i = 0; i <= N; i++) {
        if (S[i] == '0') {
            next = i;
        }
        if (i - crt == M || i == N) {
            if (next == crt) {
                ans.push_back(-1);
                break;
            } else {
                ans.push_back(next - crt);
                crt = next;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    if (ans[0] == -1) {
        cout << -1 << endl;
    } else {
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}