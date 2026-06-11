/*************************************
 * @contest:      AtCoder ABC156.
 * @user_id:      63720.
 * @user_name:    Jomoo.
 * @time:         2020-02-22.
 * @language:     C++.
 * @upload_place: Luogu.
*************************************/ 

#include <bits/stdc++.h>
using namespace std;

typedef signed char          int8;
typedef unsigned char       uint8;
typedef short                int16;
typedef unsigned short      uint16;
typedef int                  int32;
typedef unsigned            uint32;
typedef long long            int64;
typedef unsigned long long  uint64;

template <typename Int>
inline Int read()       
{
    Int flag = 1;
    char c = getchar();
    while ((!isdigit(c)) && c != '-') c = getchar();
    if (c == '-') flag = -1, c = getchar();
    Int init = c & 15;
    while (isdigit(c = getchar())) init = (init << 3) + (init << 1) + (c & 15);
    return init * flag;
}

template <typename Int>
inline Int read(char &c)       
{
    Int flag = 1;
    c = getchar();
    while ((!isdigit(c)) && c != '-') c = getchar();
    if (c == '-') flag = -1, c = getchar();
    Int init = c & 15;
    while (isdigit(c = getchar())) init = (init << 3) + (init << 1) + (c & 15);
    return init * flag;
}

template <typename Int>
inline void write(Int x)
{
    if (x < 0) putchar('-'), x = ~x + 1;
    if (x > 9) write(x / 10);
    putchar((x % 10) | 48);
}  

template <typename Int>
inline void write(Int x, char nextch)
{
    write(x);
    putchar(nextch);
}
// #define int int64
int k, q;
int d[5007], S[5007];
int n, x, m, Minus;
int cnt = 0; int64 Sk;

inline int add(int a, int b, const int ad = 1)
{
    if (b == 0) {
        cnt += ad;
#ifdef DEBUG_FUNC_ADD
        printf("%d + %d = %d -> %d\n", a, m, a + m, a);
#endif
        return a;
    } else if (a + b >= m) {
        cnt += ad;
#ifdef DEBUG_FUNC_ADD
        printf("%d + %d = %d -> %d.\n", a, b, a + b, a + b - m);
#endif
        return a + b - m;
    } else {
#ifdef DEBUG_FUNC_ADD
        printf("%d + %d = %d.\n", a, b, a + b);
#endif
        return a + b;
    }
}

void AddMul(int &now, int S, int Cnt)
{
    cnt += (int64)S * Cnt / m;
    now = add(now, (int64)S * Cnt % m);
}

signed main()
{
    k = read<int>();
    q = read<int>();
    for (int i = 1; i <= k; i++) {
        d[i] = read<int>();
    }
    for (int i = 1; i <= q; i++) {
        cnt = 0;
        n = read<int>() - 1;
        x = read<int>();
        m = read<int>();
        x = x % m;
        Minus = 0;
        Sk = 0;
        for (int i = 1; i <= k; i++) {
            Sk += d[i] % m;
            if (d[i] % m == 0) Minus++;
        }
        Sk *= (n / k);
        Minus *= (n / k);
        for (int i = 1; i <= n % k; i++) {
            Sk += d[i] % m;
            if (d[i] % m == 0) Minus++;
        }
        Sk += x;
#ifdef DEBUG_OUTPUT_ANS
        printf("cnt = %d, n = %d.\n", cnt, n);
#endif
        write(n - Sk / m - Minus, 10);
    }
    return 0;
}

// x = 1
// 1 1 0
// 1 0 1 1 0 
// 0 1 2 3 4 (pos)

/*
7 3
27 18 28 18 28 46 1000000000
1000000000 1 7
224489796 (33/147)
1000000000 2 10
214285714 (3/14)
1000000000 3 12
559523809 (47/84)
*/