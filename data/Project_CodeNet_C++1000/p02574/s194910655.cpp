#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    constexpr int A_MAX = 1000000;
    vector<int> min_factor(A_MAX + 1);
    vector<int> q(A_MAX + 1, 1);
    vector<int> primes;
    primes.reserve(A_MAX);
    for (int i = 2; i <= A_MAX; ++i) {
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
    vector<int> a(A_MAX + 1);
    for (int i = 0; i < N; ++i) {
        int A = 0;
        c = getchar_unlocked();
        do {
            A = 10 * A + c - '0';
    	} while ((c = getchar_unlocked()) >= '0');
        ++a[A];
    }
 
    bool is_pairwise_coprime = true;
    for (int n = A_MAX; n > 1; --n) {
        int a_n = a[n];
        if (a_n) {
            if (a_n > 1) {
                if (a_n == N) {
                    printf("not coprime\n");
                    return 0;
                }
                is_pairwise_coprime = false;
            }
            a[min_factor[n]] += a_n;
            a[q[n]] += a_n;
        }
    }
    if (is_pairwise_coprime) {
        printf("pairwise coprime\n");
    } else {
        printf("setwise coprime\n");
    }
 
    return 0;
}