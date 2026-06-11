#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <map>
#include <string>
#include <bitset>
#include <vector>
using namespace std;

int main() {
    long long n;
    int ans = 0;
    cin >> n;
    long long t = n - 1;
    for (long long i = 2; i * i <= t; i++)
        if (t % i == 0) {
            ans++;
            if (i * i != t) ans++;
        }
    if (t >= 2) ans++;
    for (long long i = 2; i * i <= n; i++)
        if (n % i == 0) {
            t = n;
            while (t % i == 0) t /= i;
            if (t % i == 1) ans++;
            if (i * i == n) continue;
            t = n;
            while (t % (n / i) == 0) t /= (n / i);
            if (t % (n / i) == 1) ans++;
        }
    ans++;
    printf("%d\n", ans);
    return 0;
}
