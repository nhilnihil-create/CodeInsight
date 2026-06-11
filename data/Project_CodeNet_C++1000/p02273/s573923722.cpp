#include <iostream>
#include <iomanip>
#include <complex>
using namespace std;

typedef complex<long double> P;

int n;

void dfs(const P& p1, const P& p2, int i)
{
    if(i == n){
        cout << p2.real() << ' ' << p2.imag() << endl;
        return;
    } else {
        P p3, p4, p5;
        p3 = (p2 - p1) / 3.0L + p1;
        p5 = 2.0L * (p2 - p1) / 3.0L + p1;
        //p4 = polar(abs(p5 - p3), arg(p5 - p3) + acos(-1.0L) / 3.0L) + p3;
        p4 = (p5 - p3) * polar(1.0L, acos(-1.0L) / 3.0L) + p3;
        dfs(p1, p3, i + 1);
        dfs(p3, p4, i + 1);
        dfs(p4, p5, i + 1);
        dfs(p5, p2, i + 1);
    }
}

int main()
{
    cin >> n;
    cout << setprecision(8) << fixed;
    cout << 0.0L << ' ' << 0.0L << endl;

    dfs(P(0,0), P(100,0), 0);
}