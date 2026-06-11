#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <cstdio>
#include <cstdint>
using namespace std;
typedef int_fast64_t ll;

ll c, sd = -1, sc = -1, A, M;
constexpr uint32_t buff_size = 1 << 17;
char buff[buff_size], *ci = buff + buff_size, *ce = ci, ct;

inline char readchar() {
    if (ci == ce) {fread_unlocked(buff, 1, buff_size, stdin); ci = buff;}
    return *ci++;
}

inline ll readint() {
	A = 0;
	if (ci + 16 > ce) while ((ct = readchar()) > 47) A = (A << 3) + (A << 1) + ct - 48;
    else while ((ct = *ci++) > 47) A = (A << 3) + (A << 1) + ct - 48;
    return A;
}

int main() {
    M = readint();
    while(M--) {
        sd += readint() * readint();
        sc += A;
    }
    printf("%lld\n", sc + sd / 9);
	return 0;
}
