#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int mod = (int)1e9+7;

void __print() {cerr << "]\n";}

template<typename T, typename... V>
void __print(T t, V... v)
{ cerr << t; if(sizeof...(v)) cerr << ", "; __print(v...);}

#define dbg(x...) cerr << "[" << #x << "] = ["; __print(x);

i64 modInverse(i64 k)
{
    i64 res = 1;
    i64 n = mod - 2;
    while(n) {
        if(n & 1) {
            res *= k;
            res %= mod;
        }
        k *= k;
        k %= mod;
        n /= 2;
    }
    return res;
}

int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    if((x+y)%3) {
        puts("0\n");
    } else {
        int n = (x+y);
        int m = 0;
        int k = (x+y)/3;
        int r = 0;
        for(int i = 0; i < k; i++) n--, m++;
        while(n != x && m != y && r < k) n--, m++, r++;
        if(n == x && m == y) {
            i64 kf = 1;
            for(int i = 1; i <= k; i++) {
                kf *= i;
                kf %= mod;
            }
            i64 rf = 1;
            for(int i = 1; i <= r; i++) {
                rf *= i;
                rf %= mod;
            }
            i64 krf = 1;
            for(int i = 1; i <= k-r; i++) {
                krf *= i;
                krf %= mod;
            }
            krf *= rf;
            krf %= mod;
            krf = modInverse(krf);
            printf("%lld\n", (kf*krf)%mod);
        } else {
            puts("0");
        }
    }
}
