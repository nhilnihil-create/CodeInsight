#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <cstdio>
#include <cstdint>
using namespace std;
typedef int_fast64_t ll;

unsigned int M, i = 0;
ll d, c, sd = 0, sc = 0, A;
const int cm = 1 << 17;
char cn[cm], * ci = cn + cm, ct;
inline char readchar() {
    if (ci - cn == cm) { fread_unlocked(cn, 1, cm, stdin); ci = cn; }
    return *ci++;
}
 
inline ll readint() {
	A = 0;
	if (ci - cn + 16 > cm) while ((ct = readchar()) >= '0') A = A * 10 + ct - '0';
    else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';
    return A;
}

int main() {
    M = readint();
    while(i++ != M) {
        sd += readint() * readint();
        sc += A;
    }
    printf("%lld\n", --sc + --sd / 9);
	return 0;
}