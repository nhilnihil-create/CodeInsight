#define _GLIBCXX_DEBUG
#include <iostream>
#include <cstdint>
#include <vector>
using namespace std;
using i64 = int64_t;
using vi = vector<i64>;

int main(void){
    i64 x;
    cin >> x;
    vi P5(120);
    for(i64 i=1; i<120; i++) P5[i] = i*i*i*i*i;
    for(i64 a=1; a<120; a++){
        i64 a5 = P5[a];
        for(i64 b=-a; b<a; b++){
            i64 b5 = (b>=0 ? P5[b] : -P5[-b]);
            if(a5-b5 == x){
                cout << a << ' ' << b << '\n';
                return 0;
            }
        }
    }
    return 0;
}