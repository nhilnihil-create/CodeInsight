/*
Koch Curve(https://onlinejudge.u-aizu.ac.jp/#/problems/ALDS1_5_C)
右
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <complex>
using namespace std;

#define Rep(b, e, i) for(int i = b; i <= e; i++)
#define Repr(e, b, i) for(int i = e; i >= b; i--)
#define rep(n, i) Rep(0, n-1, i)
#define repr(n, i) Repr(n-1, 0, i)
#define all(v) (v).begin(), (v).end()
#define pb(v) push_back(v)

//複素数で処理
typedef complex<double> P;

const double L = 100.0;
const double PI = 3.14159265358979323846;


//答えを格納するvector
vector <P> ans;

int N;

//再帰関数(引数に左端、右端、残りの再帰回数を渡す)
//それ以上分岐しなくなったら左端の点を返す（こうすることで点がダブらず、かつ順番になる）
void rec(P lp, P rp, int n) {
    if (n == 0) {
        ans.pb(lp);
        return;
    }
    //aはπ/3だけ回転させる複素数
    //u,s,tは問題文のものに対応
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

    //右端の点は格納されないので最後に追加
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

