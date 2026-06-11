#include <bits/stdc++.h>
using namespace std;

using LL = long long;
#ifdef __linux__
using LLL = __int128;
#else
using LLL = long long;
#endif

class IO {
#define MY_DEBUG 0
#define isdigit(x) (x >= '0' && x <= '9')
    static const int MAXSIZE = 1 << 20;
    char buf[MAXSIZE], *p1, *p2;
    char pbuf[MAXSIZE], *pp;
    int precision;

public:
#if MY_DEBUG
#else
    IO() : p1(buf), p2(buf), pp(pbuf), precision(6)
    {
    }
    ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
#endif
    inline bool blank(char ch) const
    {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    void flush()
    {
        fwrite(pbuf, 1, pp - pbuf, stdout), pp = pbuf;
    }
    void filein(const char* str) const
    {
        freopen(str, "rb", stdin);
    }
    void fileout(const char* str) const
    {
        freopen(str, "wb", stdout);
    }
    inline int getch()
    {
#if MY_DEBUG
        return getchar();
#endif
        if (p1 == p2)
            p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
        return p1 == p2 ? -1 : *p1++;
    }
    template <typename T, typename... Args>
    void read(T& x, Args&... args)
    {
        read(x);
        read(args...);
    }
    void read() {}
    template <typename T>
    void read(T& x)
    {
        double tmp = 1;
        bool sign = 0;
        x = 0;
        int ch = getch();
        for (; !isdigit(ch) && ~ch; ch = getch())
            if (ch == '-')
                sign = 1;
        for (; isdigit(ch); ch = getch())
            x = x * 10 + (ch - '0');
        if (ch == '.')
            for (ch = getch(); isdigit(ch); ch = getch())
                tmp /= 10.0, x += tmp * (ch - '0');
        if (sign)
            x = -x;
    }
    void read(char& ch)
    {
        for (ch = getch(); blank(ch) && ~ch; ch = getch())
            ;
    }
    void read(char* s)
    {
        int ch = getch();
        while (blank(ch))
            ch = getch();
        while (!blank(ch) && ~ch)
            *s++ = ch, ch = getch();
        *s = 0;
    }
    void readline(char* s)
    {
        int ch = getch();
        while (blank(ch) && ch != '\n')
            ch = getch();
        while (ch != '\n' && ~ch)
            *s++ = ch, ch = getch();
        *s = 0;
    }
    void putch(const char c)
    {
#if MY_DEBUG
        putchar(c);
#else
        if (pp - pbuf == MAXSIZE)
            fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
        *pp++ = c;
#endif
    }
    void setprecision(int n)
    {
        precision = n;
    }
    template <typename T, typename... Args>
    void write(const T& x, const Args&... args)
    {
        write(x);
        write(args...);
    }
    void write() {}
    template <typename T>
    void write(T x)
    {
        if (x < 0)
            x = -x, putch('-');
        static T sta[40];
        int top = 0;
        do
            sta[top++] = x % 10, x /= 10;
        while (x);
        while (top)
            putch(sta[--top] + '0');
    }
    void write(char c) { putch(c); }
    void write(double x)
    {
        if (x == 0) {
            putch('0'), putch('.');
            for (int i = 1; i <= precision; ++i)
                putch('0');
            return;
        }
        if (x < 0)
            putch('-'), x = -x;
        LLL n = pow(10, precision);
        double res = (LLL)(x * n + 0.5) / (n * 1.0);
        LLL y = LLL(res * n) % n;
        if (precision) {
            write(LLL(res), '.');
            int sta[20], p = 0;
            for (; p < precision; y /= 10)
                sta[++p] = y % 10;
            for (int i = p; i >= 1; i--)
                putch(sta[i] ^ 48);
        } else
            write(LLL(res));
    }
    void write(const char* s)
    {
        while (*s)
            putch(*s++);
    }
} io;
#define writeln(...) io.write(__VA_ARGS__), io.putch('\n')
#define dbg(x) io.write(#x " = "), writeln(x)
// define fast io
const int maxn = 1000005;

char str[maxn];
int A[maxn], d[maxn][2], n;
int main()
{
    io.read(str+1);
    n = strlen(str+1);
    for (int i = 1; i <= n; i++)
        A[i] = str[n-i+1] ^ 48;
    d[1][0] = A[1];
    d[1][1] = 10 - A[1];
    for (int i = 2; i <= n; i++) {
        d[i][0] = min(d[i - 1][0] + A[i], d[i - 1][1] + A[i] + 1);
        d[i][1] = min(d[i - 1][0] + 10 - A[i], d[i - 1][1] + 10 - A[i] - 1);
    }
    writeln(min(d[n][0], d[n][1]+1));
    return 0;
}