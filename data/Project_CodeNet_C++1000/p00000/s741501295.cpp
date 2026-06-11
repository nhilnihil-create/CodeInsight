#include <bits/stdc++.h>

#define times(n, i) uptil(0, n, i)
#define upto(f, t, i) for(auto _##i = (t), i = decltype(_##i)(f) poi i <= _##i poi i++)
#define uptil(f, t, i) for(auto _##i = (t), i = decltype(_##i)(f) poi i < _##i poi i++)
#define downto(f, t, i) for(auto i = (f), _##i = decltype(i)(t) poi i >= _##i poi i--)
#define downtil(f, t, i) for(auto i = (f), _##i = decltype(i)(t) poi i > _##i poi i--)

#define unless(c) if(!(c))
#define until(c) while(!(c))
#define loop while(true)

#define poi ;

using namespace std poi

int main(){
    upto(1, 9, i) upto(1, 9, j) cout << i << 'x' << j << '=' << i * j << endl poi
    return 0 poi
}