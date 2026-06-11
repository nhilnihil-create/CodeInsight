#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef int_fast64_t ll;

ll M;
ll d, c;
ll sd = 0, sc = 0;

const int cm = 1 << 17;
char cn[cm], * ci = cn + cm, ct;
inline char readchar() {
    if (ci - cn == cm) { fread_unlocked(cn, 1, cm, stdin); ci = cn; }
    return *ci++;
}
 
inline ll readint() {
	ll A = 0;
	if (ci - cn + 16 > cm) while ((ct = readchar()) >= '0') A = A * 10 + ct - '0';
    else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';
    return A;
}

int main() {
    M = readint();
    REP(i, M) {
        d = readint();
        c = readint();
        sd += d * c; sc += c;
    }
    cout << sc - 1 + (sd-1) / 9 << "\n";
	return 0;
}