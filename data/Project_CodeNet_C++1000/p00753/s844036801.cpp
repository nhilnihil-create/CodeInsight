#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

//N??\???????´???°?????????O(N log log N)
int N = 300000;
vector<int> primes;
vector<bool> is_prime(N + 1, true);
void init() {
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i <= N; i ++) {
                if (is_prime[i]) {
                        primes.push_back(i);
                        for (int j = i + i; j <= N; j += i) is_prime[j] = false;
                }
        }
}

int main() {
        int n;
        init();
        while (scanf("%d", &n), n) {
                int ans = upper_bound(primes.begin(), primes.end(), 2 * n) - upper_bound(primes.begin(), primes.end(), n);
                printf("%d\n", ans);
        }
        return 0;
}