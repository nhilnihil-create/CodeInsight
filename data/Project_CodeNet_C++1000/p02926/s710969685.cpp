
#include <iostream>
#include <limits>
#include <iomanip> 
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>

#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>

using namespace std;

typedef long long LL;

#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 


struct V {
    double x;
    double y;
    explicit V(double init_x = 0, double init_y = 0) : x(init_x), y(init_y) {}
    V(const V& rhs) : x(rhs.x), y(rhs.y) {}
    V& operator=(const V& rhs) {
        if (this != &rhs) {
            x = rhs.x;
            y = rhs.y;        
        }
        return *this;
    }
    double norm() const { return sqrt(x*x+y*y); }
};

inline double innerProduct(const V& lhs, const V& rhs) { return (lhs.x * rhs.x + lhs.y * rhs.y); }
inline V operator+(const V& lhs, const V& rhs) { return V(lhs.x + rhs.x, lhs.y + rhs.y); }

struct M {
    double a;
    double b;
    double c;
    double d;
    explicit M(double init_a = 0, double init_b = 0, double init_c = 0, double init_d = 0) : a(init_a), b(init_b), c(init_c), d(init_d) {}
    M(const M& rhs) : a(rhs.a), b(rhs.b), c(rhs.c), d(rhs.d) {}
    M& operator=(const M& rhs) {
        if (this != &rhs) {
            a = rhs.a;
            b = rhs.b;        
            c = rhs.c;
            d = rhs.d;        
        }
        return *this;
    }
};

inline M rotationMatrix(double angle) 
{
    double c = cos(angle);
    double s = sin(angle);
    return M(c, -s, s, c);
}

inline V operator*(const M& m, const V& v)
{
    return V(m.a * v.x + m.b * v.y, m.c * v.x + m.d * v.y);
}

inline M operator*(const M& lhs, const M& rhs)
{
    return M(lhs.a * rhs.a + lhs.b * rhs.c, lhs.a * rhs.b + lhs.b * rhs.d, lhs.c * rhs.a + lhs.d * rhs.c, lhs.c * rhs.b + lhs.d * rhs.d);
}


int main()
{
    int N;
    cin >> N;

    vector<V> e(N);
    for (int i = 0; i < N; ++i) {
        cin >> e[i].x >> e[i].y;
    }

    double ans = 0;
    const double EPS = 0.00000000000000000000001;
    const double cos_EPS = cos(EPS);
    const double sin_EPS = sin(EPS);
    const double cos_90 = 0;
    const double sin_90 = 1.0;

    const M m_p_EPS = rotationMatrix(EPS);
    const M m_n_EPS = rotationMatrix(-EPS);
    const M m_p_90(0, -1, 1, 0);
    const M m_n_90(0, 1, -1, 0);
    const M m1 = m_p_EPS * m_p_90;
    const M m2 = m_p_EPS * m_n_90;
    const M m3 = m_n_EPS * m_p_90;
    const M m4 = m_n_EPS * m_n_90;

    for (const V& v: e) {
        vector<V> dir(6);
        dir[0] = m1 * v; 
        dir[1] = m2 * v; 
        dir[2] = m3 * v; 
        dir[3] = m4 * v;
        dir[4] = m_p_EPS * v;
        dir[5] = m_n_EPS * v;
        for (const V& d: dir) {
            V vSum;
            for (const V& t: e) {
                if (0 <= innerProduct(t, d)) {
                    vSum = vSum + t;
                }
            }
            ans = max(ans, vSum.norm());
        }
    }

    printf("%.30f\n", ans);

    return 0;
}
