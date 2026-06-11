#define _GLIBCXX_DEBUG
#include <iostream>
#include <cstdint>
#include <algorithm>
using namespace std;
using i64 = int64_t;

int main(void){
    i64 a, b, c, d;
    cin >> a >> b >> c >> d;
    i64 ans = max(max(a*c, a*d), max(b*c, b*d));
    cout << ans << '\n';
    return 0;
}