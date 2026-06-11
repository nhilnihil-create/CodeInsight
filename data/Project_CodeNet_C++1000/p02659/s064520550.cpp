#define _GLIBCXX_DEBUG
#include <iostream>
#include <cmath>
using namespace std;
using ld = long double;
using ll = long long;

int main(void){
    ld a, b;
    cin >> a >> b;
    ll ans = nextafter(a * b, INFINITY);
    cout << ans << '\n';
    return 0;
}