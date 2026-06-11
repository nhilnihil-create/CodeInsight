#define _GLIBCXX_DEBUG
#include <iostream>
#include <cstdint>
#include <algorithm>
using namespace std;
using i64 = int64_t;

int main(void){
    i64 x, k, d, a = 0;
    cin >> x >> k >> d;
    if(x < 0) x = -x;
    if(k <= x/d) a = x-d*k;
    else if((k-(x-1)/d)%2 == 1) a = ((x+d-1)/d)*d-x;
    else a = x-(x-1)/d*d;
    cout << a << '\n';
    return 0;
}