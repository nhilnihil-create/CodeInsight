#include <bits/stdc++.h>
#include "atcoder/dsu.hpp"

#define foreach(i,v) for(auto&& i: v)
#define all(x) (x).begin(), (x).end()

typedef std::vector< std::string > VS;
typedef std::vector<int> VI;
typedef long long ll;

template <class C> C& mini(C& a, C b) { if (b < a) a = b; return a; }
template <class C> C& maxi(C& a, C b) { if (a < b) a = b; return a; }

using namespace std;

template <typename T> void read(T& x) { x.read(); }
template <typename T> void read(vector<T>& v) { for (T& x: v) read(x); }
template <typename X, typename Y> void read(pair<X, Y>& p) { read(p.first); read(p.second); }
template <> void read(int& x) { scanf("%d", &x); }
template <> void read(unsigned int& x) { scanf("%u", &x); }
template <> void read(long long& x) { scanf("%lld", &x); }
template <> void read(unsigned long long& x) { scanf("%llu", &x); }
template <typename T> void readv(vector<T>& v) { int N; read(N); v.resize(N); read(v); }
template <typename T, typename ...Ts> void read(T& x, Ts&... args) { read(x); read(args...); }

int main(int argc, const char* argv[]) {
    int N, Q;
    read(N, Q);
    atcoder::dsu dsu(N);
    while (Q --> 0) {
        int t, u, v;
        read(t, u, v);
        if (t == 0) {
            dsu.merge(u, v);
        } else {
            if (dsu.same(u, v)) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        }
    }
    return 0;
}
