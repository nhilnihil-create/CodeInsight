#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <utility>
#include <numeric>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <limits>

#define for0(i, n)    for (int i = 0  ; i <  (n); ++i)
#define for1n(i, n)   for (int i = 1  ; i <= (n); ++i)
#define for1(i, n)    for (int i = 1  ; i <  (n); ++i)
#define forn(i, n)    for (int i = 0  ; i <= (n); ++i)
#define forx(i, n, x) for (int i = (x); i <  (n); ++i)
#define forl(i, n, x, a) for (int i = (x), a = 0; a < (n);  \
                              i = (i + 1) % (n), ++a)

using namespace std;

typedef long long ll;
typedef priority_queue<ll> pq;
typedef priority_queue<ll,vector<ll> ,greater<ll>> pql;
typedef stack<ll> stk;
typedef queue<ll> qu;

template<typename T>
struct point{
    T x, y;
    point(T a = 0, T b = 0) : x(a), y(b){}
    
    point operator+(point p) const { return {p.x + x, p.y + y}; }
    point operator-(point p) const { return {p.x - x, p.y - y}; }
    T operator*(point p) const { return p.x * x + p.y * y; }
    
    point operator+=(point p) {x += p.x; y += p.y; return *this; }
    point operator-=(point p) {x -= p.x; y -= p.y; return *this; }

    T length() const { return std::sqrt(x * x + y * y); }
    
    operator T() const { return length(); }

    T angle() const { return std::atan2(y, x); }
    
    static bool angleLesser(point<T> const& p, point<T> const& q) {
        return p.angle() < q.angle();
    }
    
    static bool lengthLesser(point<T> const& p, point<T> const& q) {
        return p.length() < q.length();
    }
};


int main(void){

    int N;
    
    cin >> N;

    point<long double> v[100];
    
    for0(i, N){
        cin >> v[i].x >> v[i].y;
    }

    sort(v, v + N, point<long double>::angleLesser);

    long double result = 0;
    
    for0(i, N){
        point<long double> p = {0, 0};
        forl(j, N, i, a){            
            p += v[j];
            result = max(result, p.length());
        }
    }

    printf("%.20Lf", result);
    
    return 0;
}
