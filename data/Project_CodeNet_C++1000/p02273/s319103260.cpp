// Koch Curve
// 問題URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_C&lang=jp
// 中央*右
// 
//

#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

typedef complex<double> xy_t;
const xy_t i( 0.0, 1.0 );

int N;
xy_t A(0.0, 0.0), B(100.0, 0);

void show_vertex(xy_t p){
    printf("%.8f %.8f\n",p.real(), p.imag());
}

void koch(xy_t p1, xy_t p2, int n){
    if(n == 0) show_vertex(p1);
    else{
        xy_t vec = p2 - p1;
        xy_t s = p1 + vec * 1.0/3.0;
        xy_t t = p1 + vec * 2.0/3.0;
        double theta = 60.0*M_PI/180.0;
        xy_t buff = vec * 1.0/3.0 * exp(i * theta);
        xy_t u = s + buff;

        koch(p1, s, n-1);
        koch(s, u, n-1);
        koch(u, t, n-1);
        koch(t, p2, n-1);
    }
}

int main(){
    cin >> N;

    koch(A, B, N);
    show_vertex(B);
}

