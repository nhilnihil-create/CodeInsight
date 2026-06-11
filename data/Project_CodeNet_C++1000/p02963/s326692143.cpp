#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long S;
    cin >> S;
    long long MAX = 1e9;
    long long X1 = 0, Y1 = 0, X2 = MAX, Y2 = 1, X3, Y3;
    X3 = (MAX - S % MAX) % MAX;
    Y3 = (S + X3) / MAX;
    printf("%lld %lld %lld %lld %lld %lld\n", X1, Y1, X2, Y2, X3, Y3);
}