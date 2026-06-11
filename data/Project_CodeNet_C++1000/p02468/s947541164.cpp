#include <cstdio>
#include <cstdint>
#include <cmath>

using namespace std;

constexpr int limit = 1'000'000'007;
constexpr int exp_max = 29;

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int64_t res = m;
    int64_t m_exp[exp_max];
    m_exp[0] = m;
    int count = 1;
    int i;
    double sup = log(n) / log(2);
    for (i = 1; i <= sup; i++) {
        res *= res;
        res = res % limit;
        m_exp[i] = res;
        count *= 2;
        //printf("%d %lld %d\n", i, res, count); fflush(stdout);
    }
    for (int j = i-2; count < n; j--) {
        if (n - count < pow(2,j)) { continue; }
        res *= m_exp[j];
        res = res % limit;
        count += pow(2,j);
    }
    printf("%lld\n", res);
    return 0;
}