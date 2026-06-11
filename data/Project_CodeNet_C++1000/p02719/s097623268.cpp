#define _GLIBCXX_DEBUG
#include <iostream>
#include <cstdint>
using namespace std;
using i64 = int64_t;

int main(void){
    i64 x, k;
    cin >> x >> k;
    if(x>k) x = x-(x-1)/k*k;
    if(k-x<x) x = k-x;
    cout << x << '\n';
    return 0;
}