#define _GLIBCXX_DEBUG
#include <iostream>
#include <cstdint>
using namespace std;
using i64 = int64_t;

int main(void){
    i64 x, d = 100;
    cin >> x;
    int cnt = 0;
    while(d < x){
        d = (i64)(d+d/100);
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}