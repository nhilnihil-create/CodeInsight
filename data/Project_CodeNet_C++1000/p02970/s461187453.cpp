#include <iostream>
#include <math.h>


int main() {
    using namespace std;
    int n, D, d;
    cin >> n >> D;
    d = D * 2 + 1;
    if (n % d == 0){
        cout << n / d;
    } else {
        cout << int(floor(n / d)) + 1;
    }
    return 0;
}