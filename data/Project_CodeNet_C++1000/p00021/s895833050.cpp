#include <bits/stdc++.h>
using namespace std;
#define REP(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define rep(i,n) REP(i, 0, n)
typedef complex<double> Point;
double cross(const Point& a, const Point& b){
    return (conj(a) * b).imag();
}
int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    Point a[4];
    int N; cin >> N;
    rep(casenum, N){
        rep(i, 4) cin >> a[i].real() >> a[i].imag();
        double sum = cross(a[0] - a[1], a[2] - a[3]) / 2;
        if(abs(sum) < 1.0e-11) cout << "YES" << endl; else cout << "NO" << endl;
    }
    return 0;
}