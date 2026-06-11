#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
long long e[100010];
int main() {
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    for (long long i = 1; i <= k; i++) {
        long long m = k / i;
        long long b = 0;
        for (long long j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                b += e[j];
                if (j != i / j && j != 1) {
                    b += e[i / j];
                }
            }
        }
        if (i == 1) {
            b = 0;
        }
        long long n1 = n;
        long long ans1 = 1;
        while (n1 > 0) {
            if ((n1 & 1) == 1) {
                ans1 = ans1 * m % 1000000007;
            }
            m = m * m % 1000000007;
            n1 >>= 1;
        }
        ans += ans1 * (i - b) % 1000000007;
        ans %= 1000000007;
        e[i] = (i - b);
    }
    cout << ans << endl;
}
