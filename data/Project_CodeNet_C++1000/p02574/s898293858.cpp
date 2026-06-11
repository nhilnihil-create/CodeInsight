//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <x86intrin.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define V vector
template <typename T> bool chmin(T &a, const T &b) {if(a > b){a = b; return true;} return false;}
template <typename T> bool chmax(T &a, const T &b) {if(a < b){a = b; return true;} return false;}
template<typename A, size_t N, typename T> void Fill (A (&array)[N], const T & val) {fill ((T*)array, (T*)(array+N), val);}
V<int> dx = {-1, 1,  0, 0, -1, -1,  1, 1};
V<int> dy = { 0, 0, -1, 1, -1,  1, -1, 1};

int main () {
    int n; cin >> n;
    V<int> a(1e6+5, 0);
    int g = 0;
    rep(i, n) {
        int x; cin >> x;
        a[x]++;//a[x]:xを因数に含むものの個数
        g = __gcd(g, x);
    }
    for (int i = 1; i <= 1e6; i++) {
        for (int j = 2; i*j <= 1e6; j++) {
            a[i] += a[i*j];
        }
    }
    bool ps = true;
    for (int i = 2; i <= 1e6; i++) {
        if (a[i] > 1) ps = false;
    }
    if (ps) {
        puts("pairwise coprime");
        return 0;
    }

    if (g == 1) puts("setwise coprime");
    else puts("not coprime");

    return 0;
}