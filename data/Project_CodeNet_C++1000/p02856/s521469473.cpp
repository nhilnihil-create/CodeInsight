#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <cstdio>
#include <cstdint>
using namespace std;

int_fast8_t d;
uint_fast32_t M = 0;
uint_fast64_t c, sd = -1, sc = -1;
constexpr int buff_size = 1 << 19;
char buff[buff_size], *ci = buff + buff_size, *ce = ci, ct;

inline char read_input() {
    if (ci == ce) { fread_unlocked(buff, 1, buff_size, stdin); ci = buff; }
	return *ci++;
}

int main() {
    while((ct=read_input()) > 47) M = (M<<1) + (M<<3) + ct - 48;
    while(M--) {
        if(ci + 18 > ce) {
            d = read_input() - 48;
            read_input();
            for(c=0; (ct=read_input()) > 47;) c = (c<<1) + (c<<3) + ct - 48;
        } else {
            d = *ci - 48;
            ci += 2;
            for(c=0; *ci > 47;) c = (c<<1) + (c<<3) + *ci++ - 48;
            ci++;
        }
        sc += c;
        sd += c * d;
    }
    printf("%lld", sc + sd / 9);
	return 0;
}
