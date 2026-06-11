
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

    for (const V& v: e) {
        vector<V> dir(6);
        dir[0].x =  cos_EPS * v.x - sin_EPS * v.y; 
        dir[0].y =  sin_EPS * v.x + cos_EPS * v.y; 
        dir[1].x =  cos_90 * dir[0].x - sin_90 * dir[0].y; 
        dir[1].y =  sin_90 * dir[0].x + cos_90 * dir[0].y; 
        dir[2].x =  cos_90 * dir[0].x + sin_90 * dir[0].y; 
        dir[2].y =  -sin_90 * dir[0].x + cos_90 * dir[0].y; 
        dir[3].x =  cos_EPS * v.x + sin_EPS * v.y; 
        dir[3].y = -sin_EPS * v.x + cos_EPS * v.y; 
        dir[4].x =  cos_90 * dir[0].x - sin_90 * dir[3].y; 
        dir[4].y =  sin_90 * dir[0].x + cos_90 * dir[3].y; 
        dir[5].x =  cos_90 * dir[0].x + sin_90 * dir[3].y; 
        dir[5].y =  -sin_90 * dir[0].x + cos_90 * dir[3].y; 
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
