#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <cstdio>
#include <cstdint>
#define READINTA(X) while((ct=readchar())>='0')(X)=(X)*10+ct-'0';
#define READINTB(X) while((ct=*ci++)>='0')(X)=(X)*10+ct-'0';
using namespace std;

uint16_t d, k;
uint32_t M = 0;
int_fast64_t c, sd = 0, sc = 0;
constexpr int cm = 1 << 17;
char cn[cm], *ci = cn + cm, ct;

inline char readchar() {
    if(ci-cn==cm){fread_unlocked(cn,1,cm,stdin);ci=cn;}
    return *ci++;
}

int main() {
    READINTA(M);
    while(M--) {
        c = 0;
        if(ci-cn+20>cm) {
            d = readchar() - '0';
            readchar();
            READINTA(c);
        } else {
            d = *ci++ - '0';
            ci++;
            READINTB(c);
        }
        sc += c;
        sd += c * d;
    }
    printf("%lld\n", --sc + --sd / 9);
	return 0;
}