/*
 * by purple
 * at 12-01-01 10:50:50
 */

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define sz(x) ((int)((x).size()))
#define out(x) printf(#x" %d\n", x)
#define rep(i,n) for(int i=0;i<(n);++i)
#define repf(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 123456 * 2 + 10;

bool f[maxn];
int prime[22000], cnt = 0, n;

void makePrime() {
    for (int i = 2; i < maxn; ++i) {
        if (!f[i]) {
            prime[cnt++] = i;
        }
        for (int j = 0; j < cnt && i * prime[j] < maxn; ++j) {
            f[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}

int main() {
    makePrime();
    
    while (scanf ("%d", &n), n) {
        printf ("%d\n", upper_bound(prime, prime + cnt, 2 * n) - upper_bound(prime, prime + cnt, n));
    }
    return 0;
}