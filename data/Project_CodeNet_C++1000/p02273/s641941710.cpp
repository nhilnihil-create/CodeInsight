// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
const int INF = 1000000007;

// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// using Bint = mp::cpp_int;
// using Real = mp::number<mp::cpp_dec_float<1024>>;

struct P {
    double x, y;
};

const double th = M_PI * 60.0 / 180.0;

void Koch_n(P p1, P p2, int n){
    if(n == 0) return;

    P s, t, u;
    s.x = 2 * p1.x / 3.0 +  p2.x / 3.0;
    s.y = 2 * p1.y / 3.0 +  p2.y / 3.0;
    t.x = p1.x / 3.0 + 2 * p2.x / 3.0;
    t.y = p1.y / 3.0 + 2 * p2.y / 3.0;
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

    Koch_n(p1, s, n - 1);
    printf("%.5f %.5f\n", s.x, s.y);
    Koch_n(s, u, n - 1);
    printf("%.5f %.5f\n", u.x, u.y);
    Koch_n(u, t, n - 1);
    printf("%.5f %.5f\n", t.x, t.y);
    Koch_n(t, p2, n - 1);

}

int main(){
    int N;
    scanf("%d", &N);
    P a = {0, 0}, b = {100, 0};
    printf("%.5f %.5f\n", a.x, a.y);
    Koch_n(a, b, N);
    printf("%.5f %.5f\n", b.x, b.y);
}
