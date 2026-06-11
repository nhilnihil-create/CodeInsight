#include<cstdio>

int n;
int a[1000000], cnt[1000001];

int prime[1000];
bool is_prime[1001];

int sieve(int n) {
    int p = 0;
    for (int i = 0; i <= n; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime[p++] = i;
            for (int j = 2 * i; j <= n; j += i) is_prime[j] = false;
        }
    }
    return p;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    int p = sieve(1000);
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < n; j++) {
            int pi = prime[i];
            if (a[j] % pi == 0) cnt[pi]++;
            while (a[j] % pi == 0) a[j] /= pi;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > 1000) cnt[a[i]]++;
    }
    int ans = 0;
    for (int i = 2; i <= 1000000; i++) {
        if (cnt[i] > 1) ans = 1;
        if (cnt[i] == n) {
            ans = 2;
            break;
        }
    }

    if (ans == 0) printf("pairwise coprime\n");
    if (ans == 1) printf("setwise coprime\n");
    if (ans == 2) printf("not coprime\n");
    return 0;
}

