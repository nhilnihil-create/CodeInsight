#include <bits/stdc++.h>
 
#define A_MAX 1000000
#define A_MAX_HALF 500000
 
using namespace std;
 
int min_factor[A_MAX + 1];
int q[A_MAX + 1];
int a[A_MAX + 1];
 
int main() {
    vector<int> primes;
    primes.reserve(A_MAX_HALF);
    for (int i = 2; i <= A_MAX_HALF; ++i) {
        if (!min_factor[i]) {
            min_factor[i] = i;
            primes.push_back(i);
        }
        int min_factor_i = min_factor[i];
        for (int p : primes) {
            int n = i * p;
            if (n > A_MAX) {
                break;
            }
            min_factor[n] = p;
            if (p == min_factor_i) {
                q[n] = q[i];
                break;
            } else {
                q[n] = i;
            }
        }
    }
 
    int N = 0;
    char c = getchar_unlocked();
    do {
        N = 10 * N + c - '0';
    } while ((c = getchar_unlocked()) >= '0');
    for (int i = 0; i < N; ++i) {
        int A = 0;
        c = getchar_unlocked();
        do {
            A = 10 * A + c - '0';
    	} while ((c = getchar_unlocked()) >= '0');
        ++a[A];
    }
 
    int is_pairwise_coprime = 1;
    for (int n = A_MAX; n > 1; --n) {
        int an = a[n];
        if (an) {
            if (an > 1) {
                if (an == N) {
                    printf("not coprime\n");
                    return 0;
                }
                is_pairwise_coprime = 0;
            }
            a[min_factor[n]] += an;
            a[q[n]] += an;
        }
    }
    if (is_pairwise_coprime) {
        printf("pairwise coprime\n");
    } else {
        printf("setwise coprime\n");
    }
 
    return 0;
}