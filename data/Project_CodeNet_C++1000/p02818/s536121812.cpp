#define _GLIBCXX_DEBUG
#include <iostream>
#include <cstdint>
using namespace std;
using i64 = int64_t;

int main(void){
    i64 a, b, k;
    cin >> a >> b >> k;
    if(k <= a) a -= k;
    else if(k <= a + b){b -= k - a; a = 0;}
    else{a = 0; b = 0;}
    cout << a << ' ' << b << '\n';
    return 0;
}