#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;
using i64 = int64_t;
using vi = vector<i64>;

int main(void){
    int n;
    cin >> n;
    vi a(n);
    for(i64 &x : a){
        cin >> x;
        if(x == 0){
            cout << 0 << '\n';
            return 0;
        }
    }
    i64 p = 1;
    for(i64 &x : a){
        if(x <= 1000000000000000000LL / p) p *= x;
        else{
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << p << '\n';
    return 0;
}