#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include <complex>
using namespace std;

#define Rep(b, e, i) for(int i = b; i <= e; i++)
#define Repr(e, b, i) for(int i = e; i >= b; i--)
#define rep(n, i) Rep(0, n-1, i)
#define repr(n, i) Repr(n-1, 0, i)
#define all(v) (v).begin(), (v).end()
#define pb(v) push_back(v)
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define bitcnt(x) __builtin_popcount(x)
#define fst first
#define snd second

typedef complex<double> P;

//vector の中身を出力
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

const double L = 100.0;
const double PI = 3.14159265358979323846;

vector <P> ans;

int N;

void rec(P lp, P rp, int n) {
    if (n == 0) {
        ans.pb(lp);
        return;
    }
    P s, t, u, a;
    s = lp + (rp - lp) / 3.;
    t = lp + (rp - lp) * 2. / 3.;
    a = polar(abs(rp-lp)/3, arg(rp-lp) + PI/3.);
    u = s + a;
    rec(lp, s, n-1);
    rec(s, u, n-1);
    rec(u, t, n-1);
    rec(t, rp, n-1);
}



void solve(void){
    cin >> N;
    P p1(0., 0.);
    P p2(L, 0.);

    rec(p1, p2, N);
    ans.pb(p2);

    for (auto p : ans) {
        printf("%.6lf %.6lf\n", p.real(), p.imag());
    }

}

int main(void){
  solve();
  //cout << "yui(*-v・)yui" << endl;
  return 0;
}

