#include <bits/stdc++.h>
 
#define A_MAX 1000000
#define A_MAX_HALF 500000
 
using namespace std;
 
int min_factor[A_MAX + 1];
int q[A_MAX + 1];
int a[A_MAX + 1];
 
int main() {
    vector<int> primes{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997 };
    for (int i = 2; i <= A_MAX_HALF; ++i) {
        if (!min_factor[i]) {
            min_factor[i] = i;
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