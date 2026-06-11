#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <complex>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處
namespace Number {
    typedef long long int LL;
    // 求取 a, b 的最大公因數
    LL gcd(LL a, LL b) {
        if (a % b == 0) {
            return b;
        }
        return gcd(b, a % b);
    }
    // 求取 a, b 的最大公因數 gcd
    // 以及 x, y 使得 a*x + b*y = gcd
    LL gcd_extend(LL a, LL b, LL *x, LL *y) { 
        if (a == 0) { 
            *x = 0, *y = 1; 
            return b; 
        } 
    
        LL x1, y1; // To store results of recursive call 
        LL gcd = gcd_extend(b%a, a, &x1, &y1); 
    
        *x = y1 - (b/a) * x1; 
        *y = x1; 
    
        return gcd; 
    }
    // 求 a_inv 使得 (a * a_inv) % m = gcd(a, m)
    // 若 a, m 互質，即求 a 在 mod m 群的反元素 a_inv 
    LL mod_inv(LL a, LL m) { 
        LL x, y; 
        LL g = gcd_extend(a, m, &x, &y); 
        // 處理 x 爲負的情形 
        LL a_inv = (x%m + m) % m; 
        return a_inv;
    }
    // 求 x^n % m
    LL mod_pow(LL x, LL n, LL m) {
        if (n == 0) {
            return 1;
        } else if (n & 1) {
            LL half = mod_pow(x, n/2, m);
            return (half * half % m) * x % m;
        } else {
            LL half = mod_pow(x, n/2, m);
            return half * half % m;
        }
    }
    // 連乘
    LL mul(LL from, LL to, LL m) {
        LL ret = 1;
        for (LL i = from; i <= to; i++) {
            ret *= i;
            ret %= m;
        }
        return ret;
    }
    // 求 (C n 取 k) % m
    LL mod_comb(LL n, LL k, LL m) {
        if (n < 0 || k < 0) { return 0; }
        if (n == 0 || k == 0) {return 1;}
        LL mi = k < n-k ? k : n-k;
        LL up = mul(n - mi + 1, n, m);
        LL down = mul(1, mi, m);
        return (up * mod_inv(down, m)) % m;
    }
}

char L[100005];

const LL M = (LL)1e9 + 7;

int main() {
    scanf("%s", L);
    int n = strlen(L);
    vector<int> ones;
    for (int i = 0; i < n; i++) {
        if (L[i] == '1') { ones.push_back(i); }
    }

    // 打表
    LL ans = 0;
    for (int i = 0; i < ones.size(); i++) {
        int digit = n - ones[i];
        ans += Number::mod_pow(2, i, M) * Number::mod_pow(3, digit - 1, M);
        ans %= M;
        // ans += Number::mod_pow(2, i + 1, M);
    }
    ans += Number::mod_pow(2, ones.size(), M);
    ans %= M;
    printf("%lld\n", ans);
}
