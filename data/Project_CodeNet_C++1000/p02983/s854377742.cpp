#include <iostream>
using namespace std;
 
int main(void){
    long L, R;
    long x = 2019;
    long y = 0;
    long diff = 0;
    
    cin >> L >> R;
    diff = R-L;
    
    if (diff==1) {
        cout << (L*R)%2019;
        return 0;
    } else if (diff>=2019) {
        cout << 0;
        return 0;
    } else {
        for (long i = L; i < R; i++) {
            for (long j = i+1; j < R + 1; j++) {
                y = (i*j)%2019;
                if (x >= y) {
                    x = y;
                }
            }
        }
        cout << x;
    }
    return 0;
}
