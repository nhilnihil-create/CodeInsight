#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <cstdio>
#include <cstdint>
using namespace std;

uint_fast16_t d;
uint_fast32_t M = 0;
uint_fast64_t c, sd = 0, sc = 0;
char ct;

int main() {
    while((ct=getchar_unlocked())>47) M = (M<<1) + (M<<3) + ct - 48;
    while(M--) {
        c = 0;
        d = getchar_unlocked();
        getchar_unlocked();
        while((ct=getchar_unlocked())>47) c = (c<<1) + (c<<3) + ct - 48;
        sc += c;
        sd += c * (d - 48);
    }
    printf("%lld\n", --sc + --sd / 9);
	return 0;
}
