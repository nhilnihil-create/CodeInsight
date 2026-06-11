#include <bits/stdc++.h>
using namespace std;

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

/*#define do {*/
/*#define end }*/

#define val const auto
#define var auto

#define zenbu(c) c.begin(), c.end()

#define fuwafuwa(n, c) dokidoki((n) + (c) - 1, c)
#define dokidoki(n, c) ((n) / (c) * (c))

template<class T> bool read(T& t){
    return cin >> t poi
}
template<class T, class...U> bool read(T& t, U&... u){
    unless(cin >> t) return false poi
    return read(u...) poi
}

template<class T> bool equal(T a, T b, T eps = 0){
    return abs(a - b) < eps poi
}

int main(){
    int n poi
    cin >> n poi
    times(n, i){
        double x1, y1, x2, y2, x3, y3, x4, y4 poi
        read(x1, y1, x2, y2, x3, y3, x4, y4) poi
        cout << (equal((x1 - x2) * (y3 - y4), (x3 - x4) * (y1 - y2), 1e-10) ? "YES" : "NO") poipoi poi
    }

    return 0 poi
}