#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <queue>
#include <thread>
#include<bits/extc++.h>

using namespace __gnu_pbds;
#pragma GCC optimize("Ofast")

#define ll long long

#define gc (c = getchar())
#define gi(x) scanf("%d", &x)
#define gid(x, y) scanf("%d%d", &x, &y)
#define gll(x) scanf("%lld", &x)
#define glld(x, y) scanf("%lld%lld", &x, &y)
#define gllt(x, y, z) scanf("%lld%lld%lld", &x, &y, &z)
#define git(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define pi(x) printf("%d\n", x)
#define pr(x) return !(printf("%lld\n", (long long)(x)))
#define pcs(ch, cs, x) printf("Case %c%d: %d\n", ch, cs, x)
#define pllcs(ch, cs, x) printf("Case %c%d: %lld\n", ch, cs, x)
#define pcsyn(ch, cs, st) printf("Case %c%d: %s\n", ch, cs, (st) ? "Yes" : "No")
#define pyn(st) printf("%s\n", (st) ? "yes" : "no")
#define pryn(st) return !(printf("%s\n", (st) ? "YES" : "NO"))
#define pll(x) printf("%lld\n", x)
#define plld(x, y) printf("%lld %lld\n", x, y)

#define mp(x, y) std::make_pair(x, y)
#define fcs(x) while (x--)
#define dbg(x) std::cerr << #x << " " << x << std::endl
#define fi freopen("in.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define siz(x) (int)x.size()
#define pb(x) push_back(x)

inline long long max(long long x, long long y) { return x > y ? x : y; }

inline long long min(long long x, long long y) { return x > y ? y : x; }

long long gcd(long long x, long long y) { return y == 0 ? x : gcd(y, x % y); }


const int maxn = 1e6 + 5;

int pc;
bool pv[maxn];
int pl[maxn];
void sieve(){
    pv[1] = true;
    for (int i = 2; i <= maxn - 5; ++ i){
        if (!pv[i]) pl[++ pc] = i;
        for (int j = 1; j <= pc && i * pl[j] <= maxn - 5; ++ j){
            pv[i * pl[j]] = true;
            if (i % pl[j] == 0) break;
        }
    }
}

std::map<int, int> vis;
void fac(int x){
    if (!pv[x]) {
        vis[x] ++;
        return;
    } 
    for (int i = 1; pl[i] * pl[i] <= x; ++ i){
        if (!(x % pl[i])) {
            vis[pl[i]] ++;
            while(!(x % pl[i]))  {
                x /= pl[i];
            }
        }
    }
    if (x != 1) vis[x] ++;
}
int seq[maxn];
int main(){
    int n;
    sieve();
    gi(n);
    for (int i = 1; i <= n; ++ i) {
        gi(seq[i]);
        fac(seq[i]);
    }
    bool pr = true;
    for (auto &it : vis){
        if (it.second == n) {
           // dbg(it.first);
            return !(printf("not coprime\n"));
        }else if (it.second > 1) pr = false;
    }
    if (!pr) puts("setwise coprime");
    else puts("pairwise coprime");
}
