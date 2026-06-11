#pragma region
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, a, n) for (int i = a; i <= n; ++i)
#define per(i, a, n) for (int i = n; i >= a; --i)
namespace fastIO {
#define BUF_SIZE 100000
#define OUT_SIZE 100000
//fread->R
bool IOerror = 0;
//inline char nc(){char ch=getchar();if(ch==-1)IOerror=1;return ch;}
inline char nc() {
    static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
    if (p1 == pend) {
        p1 = buf;
        pend = buf + fread(buf, 1, BUF_SIZE, stdin);
        if (pend == p1) {
            IOerror = 1;
            return -1;
        }
    }
    return *p1++;
}
inline bool blank(char ch) { return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t'; }
template <class T>
inline bool R(T &x) {
    bool sign = 0;
    char ch = nc();
    x = 0;
    for (; blank(ch); ch = nc())
        ;
    if (IOerror) return false;
    if (ch == '-') sign = 1, ch = nc();
    for (; ch >= '0' && ch <= '9'; ch = nc()) x = x * 10 + ch - '0';
    if (sign) x = -x;
    return true;
}
inline bool R(double &x) {
    bool sign = 0;
    char ch = nc();
    x = 0;
    for (; blank(ch); ch = nc())
        ;
    if (IOerror) return false;
    if (ch == '-') sign = 1, ch = nc();
    for (; ch >= '0' && ch <= '9'; ch = nc()) x = x * 10 + ch - '0';
    if (ch == '.') {
        double tmp = 1;
        ch = nc();
        for (; ch >= '0' && ch <= '9'; ch = nc())
            tmp /= 10.0, x += tmp * (ch - '0');
    }
    if (sign)
        x = -x;
    return true;
}
inline bool R(char *s) {
    char ch = nc();
    for (; blank(ch); ch = nc())
        ;
    if (IOerror)
        return false;
    for (; !blank(ch) && !IOerror; ch = nc())
        *s++ = ch;
    *s = 0;
    return true;
}
inline bool R(char &c) {
    c = nc();
    if (IOerror) {
        c = -1;
        return false;
    }
    return true;
}
template <class T, class... U>
bool R(T &h, U &... t) { return R(h) && R(t...); }
#undef OUT_SIZE
#undef BUF_SIZE
};  // namespace fastIO
using namespace fastIO;
template <class T>
void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) { _W(x.F), putchar(' '), _W(x.S); }
template <class T>
void _W(const vector<T> &x) {
    for (auto i = x.begin(); i != x.end(); _W(*i++))
        if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &... tail) { _W(head), putchar(sizeof...(tail) ? ' ' : '\n'), W(tail...); }
#pragma endregion
const int maxn = 1e6 + 5;
int a[maxn];
int pos[maxn];
vector<int> pr;
bool vis[maxn];
int cnt[maxn];
void findprime() {
    for (ll i = 2; i < maxn; ++i) {
        if (!vis[i]) pr.push_back(i);
        for (ll j = i * i; j < maxn; j += i) {
            vis[j] = 1;
        }
    }
}
int main() {
    int n;
    R(n);
    rep(i, 1, n) R(a[i]);
    findprime();
    int f1 = 1, f2 = 1;
    rep(i, 1, n) {
        int t = a[i];
        for (auto it : pr) {
            if (t == 1) break;
            if (!vis[t]) {
                if (pos[t])
                    f1 = 0;
                else
                    pos[t] = i;
                cnt[t]++;
                t = 1;
                break;
            }
            if (t % it == 0) {
                if (pos[it])
                    f1 = 0;
                else
                    pos[it] = i;
                cnt[it]++;
                while (t % it == 0) t /= it;
            }
        }
    }
    rep(i, 2, 1e6) if (cnt[i] >= n) f2 = 0;
    if (f1)
        W("pairwise coprime");
    else if (f2)
        W("setwise coprime");
    else
        W("not coprime");
}