#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <unordered_map>

using namespace std;
using ll = long long;

void _cin(){} template <class Head, class... Tail> void _cin(Head&& head, Tail&&... tail){ cin >> head; _cin(forward<Tail>(tail)...); }
void _cout(){ cout << "\n"; } template <class Head, class... Tail> void _cout(Head&& head, Tail&&... tail){ cout << head; _cout(forward<Tail>(tail)...); }
int gcd(int a, int b){ return (b == 0) ? a : gcd(b, a % b); }
template<typename S, typename T> ostream& operator<<(ostream &os, const pair<S, T> &p){ cout << "[" << p.first << ", " << p.second << "]"; return os; }

#define Sq(x) (x)*(x)
#define For(i, n) for(int i = 0; i < (n); i ++)
#define For1(i, n) for(int i = 1; i <= (n); i ++)
#define Rep(n) For(_, n)
#define Range(c) c.begin(), c.end()
#define RevRange(c) c.rbegin(), c.rend()
#define Contains(c, x) (find(Range(c), x) != c.end())
#define Search(rb, re, x) distance(rb, find(rb, re, x))
#define Sort(a) sort(Range(a))
#define DeSort(a) sort(RevRange(a))
#define Reverse(c) reverse(Range(c))
#define Unique(a) a.erase(unique(Range(a)), a.end())
#define Cusum(T, xs, sxs) vector<T> sxs(xs.size()+1); For(i, (int)xs.size()) sxs[i+1] = sxs[i] + xs[i]
#define Cin(T, ...) T __VA_ARGS__; _cin(__VA_ARGS__)
#define Cins(T, n, xs) vector<T> xs(n); For(i, n) cin >> xs[i]
#define Cins2(T, n, xs, ys) vector<T> xs(n), ys(n); For(i, n) cin >> xs[i] >> ys[i]
#define Cins3(T, n, xs, ys, zs) vector<T> xs(n), ys(n), zs(n); For(i, n) cin >> xs[i] >> ys[i] >> zs[i]
#define Cinss(T, n, m, xs) Vec2(T, n, m, xs); For(i, n) For(j, m) cin >> xs[i][j]
#define Cinm(T, n, map) unordered_map<T, int> map; Rep(n){ Cin(T, x); map[x] ++; }
#define Cout(...) _cout(__VA_ARGS__)
#define Couts(xs) { for(const auto &e : xs) cout << e << " "; cout << "\n"; }
#define Coutyn(cond) Cout((cond) ? "yes" : "no")
#define CoutYn(cond) Cout((cond) ? "Yes" : "No")
#define CoutYN(cond) Cout((cond) ? "YES" : "NO")
#define vc vector
#define Mini(a, x) a = min(a, x)
#define Maxi(a, x) a = max(a, x)

// constexpr int MOD = 1e9+7;

#define Pt first
#define Px second.first
#define Py second.second

int main(void){
    Cin(int, n);
    vc<pair<double, pair<int, int>>> e(n);
    For(i, n){
        Cin(int, x, y);
        e[i].Px = x;
        e[i].Py = y;
        e[i].Pt = atan2(y, x);
    }
    Sort(e);
    
    double ans = 0;
    For(i, n) For(j, n+1){
        ll x = 0, y = 0;
        For(k, j) x += e[(i+k)%n].Px, y += e[(i+k)%n].Py;
        // printf("(%d, %d) %g\n", i, j, sqrt(Sq(x) + Sq(y)));
        Maxi(ans, sqrt(Sq(x) + Sq(y)));
    }
    printf("%.20f\n", ans);
}


