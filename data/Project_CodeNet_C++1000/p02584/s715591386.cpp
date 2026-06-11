#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    long long X, K, D;
    cin >> X >> K >> D;
    X = abs(X);
    if (X / D > K) {
        X -= D * K;
    }
    else {
        K -= X / D;
        X %= D;
        X -= D * (K % 2);
    }
    cout << abs(X) << endl;
}
