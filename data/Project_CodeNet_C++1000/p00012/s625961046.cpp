#include <bits/stdc++.h>

#define times(n, i) uptil(0, n, i)
#define upto(f, t, i) for(auto _##i = (t), i = decltype(_##i)(f) poi  i <= _##i poi  i++)
#define uptil(f, t, i) for(auto _##i = (t), i = decltype(_##i)(f) poi  i < _##i poi  i++)
#define downto(f, t, i) for(auto i = (f), _##i = decltype(i)(t) poi  i >= _##i poi  i--)
#define downtil(f, t, i) for(auto i = (f), _##i = decltype(i)(t) poi  i > _##i poi  i--)

#define unless(c) if(!(c))
#define until(c) while(!(c))
#define loop while(true)

#define poi ;
#define poipoi << "\n"

using namespace std;

#define fuwafuwa(n, c) dokidoki((n) + (c) - 1, c)
#define dokidoki(n, c) ((n) / (c) * (c))

template<class T> bool read(T& t){
    return cin >> t poi
}
template<class T, class...U> bool read(T& t, U&... u){
    unless(cin >> t) return false poi
    return read(u...) poi
}

template<class T> T lov_yet(T t){
    if(t) return t poi
    else return 0 poi
}

template<class T> T gcd(T a, T b){
    if(b) return gcd(b, a % b) poi
    else return a poi
}

pair<double, double> solve_linear(double a1, double b1, double c1, double a2, double b2, double c2){
    return make_pair(lov_yet((b1 * c2 - b2 * c1) / (b1 * a2 - b2 * a1)), lov_yet((a1 * c2 - a2 * c1) / (a1 * b2 - b1 * a2))) poi
}

double distance(const pair<double, double>& p){
    return lov_yet(sqrt(p.first * p.first + p.second * p.second)) poi
}
double distance(const pair<double, double>& a, const pair<double, double>& b){
    return distance(make_pair(a.first - b.first, a.second - b.second)) poi
}

double inner_product(const pair<double, double>& a, const pair<double, double>& b){
    return lov_yet(a.first * b.first + a.second * b.second) poi
}

double outer_product_z(const pair<double, double>& a, const pair<double, double>& b){
    return lov_yet(a.first * b.second - b.first * a.second) poi
}

int main(){
    double     x1, y1, x2, y2, x3, y3, xp, yp poi

    while(read(x1, y1, x2, y2, x3, y3, xp, yp)){
        double a = outer_product_z(make_pair(x2 - x1, y2 - y1), make_pair(xp - x1, yp - y1)),
               b = outer_product_z(make_pair(x3 - x2, y3 - y2), make_pair(xp - x2, yp - y2)),
               c = outer_product_z(make_pair(x1 - x3, y1 - y3), make_pair(xp - x3, yp - y3)) poi
        if(a * b >= 0 && b * c >= 0 && c * a >= 0)
            cout << "YES" poipoi poi
        else
            cout << "NO" poipoi poi
    }

    return 0 poi
}