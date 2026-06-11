#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <functional>
#include <cmath>
#include <numeric>
#define REP(i,n) for(lint i{}, i##_len=(n); i<i##_len; ++i)
#define DOUBLE_LOOP(i, h, j, w) for(lint i{}; i < (lint)(h); ++i)for(lint j{}; j < (lint)(w); ++j)
#define DOUBLE_LOOP2(i, j, n) for(lint i{}; i < (lint)(n - 1); ++i)for(lint j{i + 1}; j < (lint)(n); ++j)
#define SZ(x) ((lint)(x).size())
using lint = long long; lint N, M, H, W;
using namespace std;
const long long INF{ 1LL << 60 };
const long double PI{ 3.1415926535897932 };
const long long NUM97{ 1000000007 };
template<class T> inline bool chmax(T& x, T y) { if (x < y) { x = y; return 1; } return 0; }
template<class T> inline bool chmin(T& x, T y) { if (x > y) { x = y; return 1; } return 0; }
std::vector<std::string> field;
std::vector<std::vector<bool>> seen(H, std::vector<bool>(W));
const std::vector<int> dx{ 1, 0, -1, 0 };
const std::vector<int> dy{ 0, 1, 0, -1 };

//素数判定
bool is_prime(lint N) {
    if (N == 1) return false;
    for (lint i = 2; i * i <= N; ++i) { if (N % i == 0) return false; }
    return true;
}
//約数列挙
std::vector<lint> divisors(lint N) { std::vector<lint> divisor;
    for (lint i = 1; i * i <= N; ++i) {
        if (N % i == 0) { divisor.push_back(i);
            if (N / i != i) divisor.push_back(N / i); }
    } std::sort(divisor.begin(), divisor.end());
    divisor.erase(std::unique(divisor.begin(), divisor.end()), divisor.end());
    return divisor;
}
//素因数列挙
std::vector<lint> prime_divisors(lint N) { std::vector<lint> p_divisor;
    for (lint i = 1; i * i <= N; ++i) {
        if (N % i == 0) { if (is_prime(i)) { p_divisor.push_back(i); }
            if (N / i != i) { if (is_prime(N / i)) { p_divisor.push_back(N / i); } } }
    } std::sort(p_divisor.begin(), p_divisor.end());
        p_divisor.erase(std::unique(p_divisor.begin(), p_divisor.end()), p_divisor.end());
    return p_divisor;
}

int main() {
    lint A, B; std::cin >> A >> B;
    std::vector<lint>a = prime_divisors(A);
    std::vector<lint>b = prime_divisors(B);
    lint ans = 0;
    for(int i = 0; i < a.size(); ++i)
        for (int j = 0; j < b.size(); ++j) {
            if (a[i] == b[j])
                ++ans;
        }
    std::cout << ans + 1 << std::endl;
}