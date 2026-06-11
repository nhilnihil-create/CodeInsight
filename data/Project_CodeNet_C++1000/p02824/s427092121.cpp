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
    int N, V, P;
    Int M;
    cin >> N >> M >> V >> P;
    vector<Int> A(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<Int> cumsum(N+1);
    
    for (int i = 1; i <= N; i++) {
        cumsum[i] = A[i] + cumsum[i-1];
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        // cout << "Checking : A" << i << " = " << A[i] << endl; 
        Int voted_Ai = A[i] + M;
        int greater_idx = (int)(lower_bound(A.begin(), A.end(), voted_Ai + 1) - A.begin());
        int less_or_equal_idx = (int)(lower_bound(A.begin(), A.end(), A[i] + 1) - A.begin()) - 1;
        int remain_V = V - (N - greater_idx + 1) - less_or_equal_idx;
        if (N - greater_idx + 1 > P - 1) continue;
        int already_voted = 0;
        if (P - (N - greater_idx + 2) >= 0) {
            remain_V -= P - (N - greater_idx + 2);
            already_voted = P - (N - greater_idx + 2);
        }
        if (remain_V <= 0) {
            ans++;
        } else {
            Int sum = (A[i] + M) * (greater_idx - 1 - already_voted - less_or_equal_idx);
            sum -= cumsum[greater_idx - 1 - already_voted] - cumsum[less_or_equal_idx];
            // cout << "remain_V = " << remain_V << " , greater_idx = " << greater_idx << " , less_or_equal_ = " << less_or_equal_idx << endl;
            if (sum >= remain_V * M) {
                ans++;
            } 
        }
    }
    cout << ans << endl;
}