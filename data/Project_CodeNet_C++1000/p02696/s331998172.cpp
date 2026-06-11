#define GLIBCXX_DEBUG
#include <iostream>
#include <cstdint>
using namespace std;
using i64 = int64_t;

int main(void){
    i64 a, b, x;
    cin >> a >> b >> x;
    if(x >= b) x = b-1;
    cout << a*x/b << '\n';
    return 0;
}